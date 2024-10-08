#pragma once

// 单链表栈
typedef struct _cstack_node {
    void *value;
    struct _cstack_node *next;
}cstack_node;

typedef struct {
    cstack_node *start_node;
    cstack_node *head;      // 入栈和出栈的节点
} cstack;

cstack* cstack_init();