#pragma once

// #define TABLE_MAX_PAGES         100
// #define PAGE_SIZE               4096
// #define COLUMN_USERNAME_SIZE    32
// #define COLUMN_EMAIL_SIZE       255

#include <stdint.h>
#include <stdbool.h>

#include "defs.h"
#include "io/pager.h"

/**
 * @note: 不能写成: #define size_of_attribue(Struct, Attribute) sizeof(Struct.Attribute)
 * 因为sizeof运算符在C和C++中不能直接用于结构体成员，而必须用于指向结构体的指针.
 *
 * @details
 * 1.sizeof运算符: sizeof运算符用于计算数据类型或对象的大小(以字节为单位)。在C和C++中,sizeof可以用于
 * 基本数据类型、数组、指针、结构体等。
 * 2.当sizeof用于结构体成员时，它必修作用于一个指向该结构体的指针。例如sizeof(((Struct*)0)->Attribute)
 * 是合法的，因为((Struct*)0)是一个指向Struct类型的指针。而Attribute是该结构体的一个成员.
 */
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

/**
* @brief 要存储的表内每行的元素类型和名称
*/
typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE+1]; // +1的原因是为了让最后一个字符设置为\0以确保不会出现字符过长导致乱码的情况,下同
    char email[COLUMN_EMAIL_SIZE+1];
} Row;

/*
    Store rows in blocks of memory called pages
    Each page stores as many rows as it can fit
    Rows are serialized into a compact representation with each page
    Pages are only allocated as needed
    Keep a fixed-size array of pointers to pages
*/


/*
    a Table structure that points to pages of rows and keeps track
    of how many rows there are:
 */
typedef struct {
    // void *pages[TABLE_MAX_PAGES];
    Pager *pager;
    uint32_t num_rows;
}Table;

/**
 * @brief Cursor类用于保存cursor的一个类,cursor用于指向表中的某一行
 * @param table Cursor类对象指向的表
 * @param row_num 当前cursor指向第几行数据
 * @param end_of_table 判断当前cursor指向的行是否是表末尾行 
 */
typedef struct {
    Table *table;
    uint32_t row_num;
    bool end_of_table;
} Cursor;

Table* db_open(const char *filename);
void db_close(Table *table);
void serialize_row(Row* _src, void *_dst);
void deserialize_row(void *_src, Row *_dst);
[[deprecated]]void* row_slot(Table *table, uint32_t row_num);
void print_row(Row *row);


Cursor *table_start(Table *table);
Cursor *table_end(Table *table);
void *cursor_value(Cursor *cursor);     // 替代row_slot函数
void cursor_advance(Cursor *cursor);
