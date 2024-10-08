#include "binary_tree/bt_node.h"
#include <unistd.h>
#include <stdlib.h>

bt_node *create_node(void *val)
{
   bt_node *node = (bt_node*)malloc(sizeof(bt_node));
   if(node == NULL)
        return NULL;
    node->value = val;
    return node;
}

/**
 * @brief 递归法中序遍历输出节点信息
 * @param root 二叉树的根节点
 * @param get_value 需要另外传入的打印节点数据的函数,类型为void f(bt_node *root)
 * @note 二叉树节点的值设置为void*是为了能够存储多种数据(包含基本数据类型和非基本数据类型),
 * 所以这里将需要打印节点信息的函数用为回调函数传入,其他几个traversal函数也一样的用法
 */
void inOrderTraversal(bt_node *root, void (*print_node)(bt_node *))
{
    if(root == NULL)
        return;
    inOrderTraversal(root->left, print_node);
    print_node(root);
    inOrderTraversal(root->right, print_node);
    return;
}

/**
 * @brief 递归法前序遍历输出节点信息
 * @param root 
 * @param print_node 
 */
void preOrderTraversal(bt_node *root, void (*print_node)(bt_node *))
{
    if(root == NULL)
        return;
    preOrderTraversal(root->left, print_node);
    preOrderTraversal(root->right, print_node);
    print_node(root);
    return;
}

void postOrderTraversal(bt_node *root, void (*print_node)(bt_node *))
{
    if(root == NULL)
        return;
    print_node(root);
    postOrderTraversal(root->left, print_node);
    postOrderTraversal(root->right, print_node);
    return;
}

/**
 * @brief 迭代法实现二叉树层序遍历
 * @param root 
 * @param print_node 
 * @note 采用自己实现的单链队列来实现
 */
void cq_level_traversal(bt_node *root, void (*print_node)(bt_node *))
{
    bt_node *node;
    c_queue *cq = cqueue_init();
    if(root == NULL)
        return;
    cqueue_push(cq, root);
    while(!is_cqueue_empty(cq))
    {
        cqueue_pop(cq, (void*)&node);
        print_node(node);
        if(node->left)
            cqueue_push(cq, node->left);
        if(node->right)
            cqueue_push(cq, node->right);
    }
    garbage_collect(cq);
    free(cq);
}