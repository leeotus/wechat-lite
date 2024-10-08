#include "queue/c_memqueue.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief 创建一个带有内存池的单链队列
 * @return 成功申请内存返回指向队列的指针,否则返回NULL
 */
mem_cqueue *create_mem_cqueue()
{
    mem_cqueue *mcq = (mem_cqueue *)malloc(sizeof(mem_cqueue));
    if(mcq == NULL)
        return NULL;
    mcq->cq_start_node = (mem_cqueue_node *)malloc(sizeof(mem_cqueue_node));
    mcq->mp = create_mem_pool(sizeof(mem_cqueue_node));
    if(mcq->cq_start_node == NULL || mcq->mp == NULL)
    {
        free(mcq);
        return NULL;
    }
    mcq->head = mcq->cq_start_node;
    mcq->tail = mcq->cq_start_node;
    mcq->cqueue_len = 0;
    return mcq;
}

/**
 * @brief 将数据push进去单链队列中
 * @param mcq 带有内存池的单链队列指针
 * @param val 需要push进去队列的数据
 * @return 成功返回0,否则返回-1
 */
int mem_cqueue_push(mem_cqueue *mcq, void *val)
{
    mem_cqueue_node *node = (mem_cqueue_node*)alloc_from_mempool(mcq->mp);
    if(node == NULL)
        return -1;
    node->value = val;
    node->next = mcq->tail->next;
    mcq->tail = node;
    mcq->head->next = node;
    mcq->cqueue_len += 1;
    return 0;
}

/**
 * @brief 将数据从单链队列中取出,存放到ptr指向的内存地址中
 * @param mcq 指向带有内存池的单链队列的指针
 * @param ptr 返回数据的指针
 */
void mem_cqueue_pop(mem_cqueue *mcq, void **ptr)
{
    if(is_memqueue_empty(mcq))
        return;
    mcq->head = mcq->head->next;
    *ptr = mcq->head->value;
    mcq->head->value = NULL;
}

/**
 * @brief 判断单链队列是否为空
 * @return 队列为空返回true,否则返回false
 */
inline bool is_memqueue_empty(mem_cqueue *mcq)
{
    return (mcq->head == mcq->tail) ? true : false;
}

/**
 * @brief 获取队列内元素的个数
 * @param mcq 指向带有内存池管理的单链队列的指针
 * @return 返回队列内元素的个数
 */
size_t memqueue_elements_size(mem_cqueue *mcq)
{
    size_t res = 1;
    if(is_memqueue_empty(mcq))
        return 0;
    mem_cqueue_node *start = mcq->head;
    while(start->next != mcq->tail)
    {
        res += 1;
        start = start->next;
    }
    return res;
}

/**
 * @brief 内存回收
 * @note 将mcq中mcq->cq_startnode到mcq->head之间的内存空间回收到内存池中
 */
void garbage_mem_collect(mem_cqueue *mcq)
{
    if(mcq->cq_start_node == mcq->head)
        return;
    while(mcq->cq_start_node != mcq->head)
    {
        mem_cqueue_node *tmp = mcq->cq_start_node;
        mcq->cq_start_node = mcq->cq_start_node->next;
        recyle_mem_avail(mcq->mp, (void**)&tmp);
    }
}