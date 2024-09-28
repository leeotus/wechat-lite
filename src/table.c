#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 * @brief Create a new table object
 * 
 * @param table 
 * @return int 成功返回0,失败返回-1
 */
Table* create_new_table()
{
    int i;
    Table *table = (Table *)malloc(sizeof(Table));
    if(table == NULL)
        return NULL;
    table->num_rows = 0;
    for(i=0;i<TABLE_MAX_PAGES;++i)
    {
        table->pages[i] = NULL;
    }
    return table;
}

void free_table(Table *table)
{
    for(int i=0;table->pages[i];++i)
        free(table->pages[i]);
    free(table);
}

/**
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
    void *page = table->pages[page_num];    // 获取第row_num行数据所存储的页面数
    if(page == NULL)
    {
        // ! 只有在我们需要访问某个页面的时候我们才为之分配内存
        // ~ tip:可以将table看作哈希表(只不过数据库里用的是B树),那么row_num可以看作是
        // ~ 一个hash key. 这样就可以理解这个函数的意义了
        table->pages[page_num] = malloc(PAGE_SIZE);
        page = table->pages[page_num];
    }

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