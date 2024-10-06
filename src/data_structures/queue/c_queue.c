#include "queue/c_queue.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief 初始化一个队列 
 * @return c_queue* 返回指向一个队列的指针 
 */
c_queue* cqueue_init()
{
    c_queue *queue = (c_queue*)malloc(sizeof(c_queue));
    if(queue == NULL)
        return NULL;
    queue->queue_size = 0;
    queue->cq_node = (cq_node*)malloc(sizeof(cq_node));
    if (queue->cq_node == NULL) {
        free(queue);
        return NULL;
    }
    queue->cq_node->next = NULL;
    // 初始化head和tail两个节点指针
    queue->head = queue->cq_node;
    queue->tail = queue->cq_node; 
    return queue;
}

/**
 * @brief 获取目前分配给队列的所有节点个数,也就是队列的长度
 * @param c_queue* 指向单链表队列的指针
 * @return uint32_t
 * @note 队列的长度不一定就是元素的个数 
 */
uint32_t cqueue_len(c_queue *cq)
{
    return cq->queue_size; 
}

/**
 * @brief 获取单链表队列内的元素个数
 * @param cq 
 * @return uint32_t 
 */
uint32_t cqueue_size(c_queue* cq)
{
    uint32_t res = 0;
    if(cq->head == cq->cq_node || cq->head == cq->tail)
        return 0;
    else {
        cq_node *begin = cq->head;
        while(begin != cq->tail)
        {
            res += 1;
            begin = begin->next;
        }
    }
    return res;
}

/**
 * @brief 将val指向的数据推入单链队列中
 * @param cq 
 * @param val 
 * @return int 成功返回0,失败返回-1 
 */
int cqueue_push(c_queue *cq, void *val)
{
    // TODO:先不考虑是否链表中有多余的节点内存可以使用:
    cq_node *node = (cq_node*)malloc(sizeof(cq_node));
    if(node == NULL)
    {
        free(node);
        return OPERATION_FAILURE;
    }
    node->value = val;
    // 将节点插入到tail之后:
    cq->tail->next = node;
    cq->tail = node;
    cq->queue_size += 1;
    return OPERATION_SUCCESS;
}

/**
 * @brief 将数据从单链队列中取出
 * @param cq 
 * @param val 
 * @return int 成功返回0,失败返回-1 
 */
int cqueue_pop(c_queue *cq, void *val)
{
    // 先判断单链队列中是否有元素
    if(cq->head == cq->tail)
        return OPERATION_FAILURE;
    cq->head = cq->head->next;
    val = cq->head->value;      // 获取的数据指针
    cq->head->value = NULL;
    return OPERATION_SUCCESS;
}

/**
 * @brief 获取cq和head之间是否有空闲的节点内存未使用
 * @param cq 
 * @return cq_node* 如果有未使用的节点内存,将其返回
 */
cq_node *lookup(c_queue *cq)
{

}