#include "stack/c_stack.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief 初始化一个单链栈
 * @return cstack* 
 * @version 2.0
 * @note 加入内存池机制
 */
cstack *cstack_init()
{
    cstack *cs = (cstack *)malloc(sizeof(cstack));
    if (cs == NULL)
        return NULL;
    cs->stk_node = (cstack_node*)malloc(sizeof(cstack_node));
    if(cs->stk_node == NULL)
    {
        free(cs);
        cs = NULL;
    }
    // 创建内存池
    cs->mp = create_mem_pool(sizeof(cstack_node));
    return cs;
}

/**
 * @brief 向单链栈push入数据
 * @param cs 指向单链栈对象的指针
 * @param val 指向数据的指针,这里数据的类型设置为void*指针,是为了兼容所有的数据类型
 * @return 成功返回0,失败返回-1
 */
int cstack_push(cstack *cs, void *val)
{
    cstack_node *node = (cstack_node *)malloc(sizeof(cstack_node));
    cstack_node *insert_node = (cstack_node *)alloc_from_mempool(cs->mp);
    if(node == NULL)
        return -1;
    node->value = val;
    node->next = cs->stk_node->next;
    cs->stk_node->next = node;
    return 0;
}

/**
 * @brief 将数据pop出去,并将stack内的内存空间回收给内存池
 * @param cs 指向单链栈的指针
 * @param ptr 指向要返回数据的指针
 */
void cstack_pop(cstack *cs, void **ptr)
{
    if(is_cstack_empty(cs))     // 如果栈为空
        return;
    cstack_node *node_to_pop = cs->stk_node->next;
    cs->stk_node->next = node_to_pop->next;
    *ptr = node_to_pop->value;
    recyle_mem_avail(cs->mp, (void **)&node_to_pop);
}

/**
 * @brief 判断单链栈是否为空
 */
inline bool is_cstack_empty(cstack *cs)
{
    return (cs->stk_node->next == NULL) ? true : false; 
}
