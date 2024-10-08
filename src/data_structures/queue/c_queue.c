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
    queue->cq_node = (cq_node*)malloc(sizeof(cq_node));
    if (queue->cq_node == NULL) {
        free(queue);
        return NULL;
    }
    queue->cq_node->next = NULL;
    queue->queue_size = 0;
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
inline uint32_t cqueue_len(c_queue *cq)
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
    if(cq->head == cq->tail)
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
    cq_node *node;
    node = lookup(cq);      // 查询单链队列中是否有多余的节点内存
    if(node == NULL)
        node = (cq_node*)malloc(sizeof(cq_node));
    if(node == NULL)
    {
        // TODO: 之后可能不考虑那么快malloc/free节点,而是选择将节点内存保存起来,需要时候再拿出来用
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
 * @note 因为该函数希望能够修改传入的指针所指向的地址,所以只用指向指针的指针作为参数
 * 如果写成参数void *val,这样做的话不会将值传递会调用者,因为val是一个局部
 * 变量,他的值会在函数返回后被销毁.
 */
int cqueue_pop(c_queue *cq, void **val)
{
    // 先判断单链队列中是否有元素
    if(cq->head == cq->tail)
        return OPERATION_FAILURE;
    cq->head = cq->head->next;
    *val = cq->head->value;      // 获取的数据指针
    return OPERATION_SUCCESS;
}

/**
 * @brief 获取cq和head之间是否有空闲的节点内存未使用
 * @param cq 
 * @return cq_node* 如果有未使用的节点内存,将其返回,否则返回NULL
 */
cq_node *lookup(c_queue *cq)
{
    if(cq->cq_node == cq->head || cq->cq_node->next == cq->head)
        return NULL;
    cq_node *node = cq->cq_node->next;
    cq->cq_node->next = node->next;
    cq->queue_size -= 1;
    return node;
}

/**
 * @brief 垃圾回收,将队列中不需要用到的节点内存回收
 * @param cq 
 */
void garbage_collect(c_queue *cq)
{
    while(cq->cq_node != cq->head)
    {
        cq_node *tmp = cq->cq_node;
        cq->cq_node = cq->cq_node->next;
        free(tmp);
        cq->queue_size -= 1;
    }
}


bool is_cqueue_empty(c_queue *cq)
{
    if (cq->head == cq->tail) {
        return true;
    }
    return false;
}