#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "mem_pool/mempool.h"

// 单链表栈
typedef struct _cstack_node {
    void *value;
    struct _cstack_node *next;
}cstack_node;

typedef struct {
    cstack_node *stk_node;
    mem_pool *mp;
} cstack;

cstack* cstack_init();
int cstack_push(cstack *cs, void *val);
void cstack_pop(cstack *cs, void **ptr);
bool is_cstack_empty(cstack *cs);