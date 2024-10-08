#pragma once

#include <unistd.h>
#include "queue/c_queue.h"

typedef struct _bt_node {
    struct _bt_node *left, *right;
    void *value;
} bt_node;

bt_node *create_node(void *val);
void inOrderTraversal(bt_node *root, void (*print_node)(bt_node*));       // 中序遍历
void preOrderTraversal(bt_node *root, void (*print_node)(bt_node*));
void postOrderTraversal(bt_node *root, void (*print_node)(bt_node*));

void cq_level_traversal(bt_node *root, void (*print_node)(bt_node*));