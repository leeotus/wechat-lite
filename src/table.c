#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const uint32_t ID_SIZE = size_of_attribute(Row, id);
const uint32_t USERNAME_SIZE = size_of_attribute(Row, username);
const uint32_t EMAIL_SIZE = size_of_attribute(Row, email);
const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;                    // 每一页可以存放多少行(Row)数据
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;        // 每个表最多可以放多少行(Row)数据

/**
 * @brief 将行(Row)数据(即,每一个数据表元素信息)存储到相邻的内存里
 * @param source 要存储的数据
 * @param destination 指向内存地址的指针
 */
void serialize_row(Row *_src, void *_dst)
{
    // ~ tips: 想象成将数据存储在内存的同一行上
    memcpy(_dst+ID_OFFSET, &(_src->id), ID_SIZE);
    memcpy(_dst+USERNAME_OFFSET, &(_src->username), USERNAME_SIZE);
    memcpy(_dst+EMAIL_OFFSET, &(_src->email), EMAIL_SIZE);
}

void deserialize_row(void *_src, Row *_dst)
{
    memcpy(&(_dst->id), _src+ID_OFFSET, ID_SIZE);
    memcpy(&(_dst->username), _src+USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&(_dst->email), _src+EMAIL_OFFSET, EMAIL_SIZE);
}

/**
 * @brief 创建一个Pager对象用于管理页面,创建一个Table对象用于管理表
 * 1.Opening the database file
 * 2.Initializing a pager data structure
 * 3.Initializing a table data structure
 * @param filename 数据库文件名
 * @return int 成功返回0,失败返回-1
 */
Table* db_open(const char *filename)
{
    Pager *pager = pager_open(filename);
    uint32_t num_rows = pager->file_length / ROW_SIZE;      // 获取数据库文件里有多少行数据
    Table *table = (Table *)malloc(sizeof(Table));
    table->pager = pager;
    table->num_rows = num_rows;
    return table;
}

/**
 * @brief 当退出数据库关闭程序时候,需要将整个数据都写回到数据库文件中
 * 以及释放其他的内存空间
 * @param table 
 */
void db_close(Table *table)
{
    int i;
    Pager *pager = table->pager;
    // table->num_rows指的是当前表有多少行数据,table->num_rows / ROWS_PER_PAGE
    // 意味着我们当前表中有多少页数据.
    uint32_t num_full_pages = table->num_rows / ROWS_PER_PAGE;

    // 如果在遍寻table的num_full_pages个页面的时候,发现有null页面,说明该页面并没有被使用,因此需要跳过    
    for(i=0;i<num_full_pages;++i)
    {
        if(pager->pages[i] == NULL)
            continue;
        // 否则我们需要将数据写回数据库文件中
        pager_flush(pager, i, PAGE_SIZE);
        // 将页面写回数据库文件之后需要释放指针
        free(pager->pages[i]);
        pager->pages[i] = NULL;
    }

    // 最后可能还会有多余的不足一个页面行数据需要写回到数据库文件中
    uint32_t num_additional_rows = table->num_rows % ROWS_PER_PAGE;
    if(num_additional_rows > 0)
    {
        if(pager->pages[num_full_pages] != NULL)
        {
            pager_flush(pager, num_full_pages, num_additional_rows * ROW_SIZE);
            free(pager->pages[num_full_pages]);
            pager->pages[num_full_pages] = NULL;
        }
    }

    // 最后是要关闭数据库文件
    int res = close(pager->file_descriptor);
    if(res == -1)
    {
        printf("Failed to close db file!\r\n");
        exit(EXIT_FAILURE);
    }

    // 释放指针
    free(pager);
    free(table);
}

/**
 * @deprecated 目前已经使用另外一个函数:#include "table.h"==> cursor_value
 * @brief 获取在指定行数的内存地址
 * @param table 
 * @param row_num 
 * @return void* 返回指向我们要查询的那一行(Row)的内存指针
 * @note 我们现在用类似数组的形式存储表，每个表的每一行(Row),存储一个数据
 * 由于这是类似内存中的一个分页表,所以每ROWS_PER_PAGE行数的数据存储在同一页
 * 要知道row_num指定的是那一行,必须要先知道该行存储在哪一页上
 */
void *row_slot(Table *table, uint32_t row_num)
{
    uint32_t page_num = row_num / ROWS_PER_PAGE;
    void *page = get_page(table->pager, row_num);

    uint32_t row_offset = row_num % ROWS_PER_PAGE;
    uint32_t byte_offset = row_offset * ROW_SIZE;
    return page + byte_offset;
}

/**
 * @brief 打印行数据
 */
void print_row(Row *row)
{
    printf("(%d, %s, %s)\r\n", row->id, row->username, row->email);
}

/**
 * @brief 返回一个指向表第一行的Cursor对象
 * @param table 
 * @return Cursor* 
 * @note table_end函数以此类推
 */
Cursor *table_start(Table *table)
{
    Cursor *cursor = (Cursor *)malloc(sizeof(Cursor));
    cursor->table = table;
    cursor->row_num = 0;
    cursor->end_of_table = (cursor->row_num == table->num_rows);
    return cursor;
}

Cursor *table_end(Table *table)
{
    Cursor *cursor = (Cursor *)malloc(sizeof(Cursor));
    cursor->table = table;
    cursor->row_num = table->num_rows;
    cursor->end_of_table = true;
    return cursor;
}

/**
 * @brief 获取cursor指向行数的数据
 * 
 * @param cursor 
 * @return void* 返回对应行数的Row对象,以便获取数据
 */
void *cursor_value(Cursor *cursor)
{
    // 获取当前cursor指向的是第几行
    uint32_t current_row_num = cursor->row_num;
    // 查看当前cursor指向的行数位于第几页
    uint32_t current_page_num = current_row_num / ROWS_PER_PAGE;
    // 获取当前页面的Pager指针
    Pager *pager = cursor->table->pager;
    void *page = get_page(pager, current_page_num);
    
    uint32_t row_offset = current_row_num % ROWS_PER_PAGE;
    uint32_t byte_offset = row_offset * ROW_SIZE;

    return page + byte_offset;
}

/**
 * @brief 将光标向下移动一行
 * @param cursor 
 */
void cursor_advance(Cursor *cursor)
{
    // 如果光标原本就是在表末尾,那么无需作任何操作
    if(cursor->end_of_table)
        return;
    cursor->row_num += 1;
    // 移动光标之后如果光标在表的最后一行,则设置end_of_table为true
    if(cursor->row_num == cursor->table->num_rows)
        cursor->end_of_table = true;
}