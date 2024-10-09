#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "mem_pool/mempool.h"

typedef struct __bt_mem_node {
    void *val;
    struct __bt_mem_node *left, *right;
}bt_mem_node;

typedef struct {
    bt_mem_node *node;
    mem_pool *mp;
} bt_mem_tree;
