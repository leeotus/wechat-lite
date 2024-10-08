#pragma once

#include <unistd.h>
#include <stdbool.h>

#define     INITIAL_MEMSIZE         16
#define     MEMPOOL_CHUNKS          8
#define     GROWTH_FACTOR           2
#define     GARBAGE_COLLECT_THRESHOLD   0.7

typedef struct _free_mem_avail_linker {
    void *node;
    struct _free_mem_avail_linker *next;
}free_linker;

/**
 * @brief 内存池类
 */
typedef struct {
    ssize_t size_of_data;      // 记录数据的长度
    ssize_t cur_chunk_num;      // 当前的内存池编号
    ssize_t cur_chunk_size;  // 当前内存池的大小
    ssize_t cur_chunk_cursor;    // 指向当前内存用到哪个位置

    // 内存池申请的空间保存在这里
    // TODO: 如果超出了MEMPOOL_CHUNKS的内存呢?  realloc? or void **mpool?
    void *mpool[MEMPOOL_CHUNKS];

    // 释放内存的时候收回该单链表中,以供后续可能的使用
    free_linker *avail;
}mem_pool;

mem_pool *create_mem_pool(ssize_t size);
bool is_freelinker_available(mem_pool *mp);

void *alloc_from_mempool(mem_pool *mp);
void realloc_next_chunk(mem_pool *mp);
void recyle_mem_avail(mem_pool *mp, void **ptr);

// TODO: 垃圾回收
void garbage_collect(mem_pool *mp);
void destroy_mempool(mem_pool **mp);
