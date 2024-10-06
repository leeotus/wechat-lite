#ifndef __PAGER_H__
#define __PAGER_H__

#include "defs.h"
#include <stdint.h>
#include <fcntl.h>

/**
 * @brief pager类负责对硬盘进行操作,当我们需要获取每一页的数据不在内存之上
 * 时,我们需要从硬盘中读取所需的数据,然后将其写入内存,供程序运行时使用
 */

/**
 * @brief pager类用于保存数据库文件描述符以及记录数据库文件内容的长度
 * (数据库文件内容的长度也就反应了有多少行数据)
 * 
 * @param file_descriptor 存储文件描述符
 * @param file_length 使用lseek从文件尾到文件头可以知道文件的内容长度,用该
 * 参数除以PAGE_SIZE即可得知有多少页面,除以ROW_SIZE即可得知有多少行(Row)数据
 * @param pages 用于存储页面(一共有TABLE_MAX_PAGES个页面,每个页面存储ROW_SIZE
 * 行数据) 
 */
typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void *pages[TABLE_MAX_PAGES];
} Pager;

Pager* pager_open(const char *filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);

#endif
