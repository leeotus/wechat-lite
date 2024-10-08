#pragma once

#include <stdint.h>
#include <stdbool.h>

#define OPERATION_SUCCESS 0
#define OPERATION_FAILURE -1

// 队列的每个节点元素类
typedef  struct _queue_elemnt
{
    void *value; // 存储数据
    struct _queue_elemnt *next;
} cq_node;

// ?单链表队列
typedef struct 
{
    uint32_t queue_size;    // 记录队列链表的当前长度
    cq_node* cq_node;        // 单链表的起始节点
    cq_node *head, *tail; // 保存每个队列的头元素和尾元素
}c_queue;

c_queue* cqueue_init();
uint32_t cqueue_len(c_queue* cq);
uint32_t cqueue_size(c_queue* cq);
int cqueue_push(c_queue *cq, void *val);
int cqueue_pop(c_queue *cq, void **val);
bool is_cqueue_empty(c_queue *cq);

cq_node *lookup(c_queue *cq);
void garbage_collect(c_queue *cq);
