#include "stack/c_stack.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief 初始化一个单链栈
 * @return cstack* 
 */
cstack *cstack_init()
{
    cstack *cs = (cstack *)malloc(sizeof(cstack));
    if (cs == NULL)
        return NULL;
    cs->start_node = (cstack_node*)malloc(sizeof(cstack_node));
    if(cs->start_node == NULL)
    {
        free(cs);
        cs = NULL;
    }
    cs->head = cs->start_node;
    return cs;
}