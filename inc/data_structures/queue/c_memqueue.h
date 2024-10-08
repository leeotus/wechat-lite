#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "mem_pool/mempool.h"

typedef struct __mem_cqueue_node
{
    void *value;
    struct __mem_cqueue_node *next;
}mem_cqueue_node;

typedef struct {
    size_t cqueue_len;      // 分配给队列的内存长度,而不是队列中元素的个数!
    mem_cqueue_node *cq_start_node;
    mem_cqueue_node *head, *tail;
    mem_pool *mp;
}mem_cqueue;

mem_cqueue *create_mem_cqueue();
int mem_cqueue_push(mem_cqueue *mcq, void *val);
void mem_cqueue_pop(mem_cqueue *mcq, void **ptr);

bool is_memqueue_empty(mem_cqueue *mcq);
size_t memqueue_elements_size(mem_cqueue *mcq);
void garbage_mem_collect(mem_cqueue *mcq);