#include "list/c_list.h"

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief 初始化一个单链表
 * @param list 传入单链表空指针,成功返回的话也通过这个指针访问单链表
 * @return int 成功返回0,失败返回-1
 */
int c_list_init(CList *list)
{
    list = (CList *)malloc(sizeof(CList));
    if (list == NULL) 
        return -1;
    list->next = NULL;
    return 0;
}

/**
 * @brief 为新的元素分配内存空间,之后将其插入到原本的单链表中
 * @param list 要插入的单链表
 * @param val 要插入的元素
 * @return int 成功返回0,失败返回-1
 */
int c_list_push(CList *list, void *val)
{
    CList *new_item = (CList *)malloc(sizeof(CList));
    if(new_item == NULL)
        return -1;
    new_item->val = val;
    new_item->next = list->next;
    list->next = new_item;
    return 0;
}

/**
 * @brief 获取单链表的元素个数
 * @param list 指向单链表的指针
 * @return int 返回单链表的元素个数 
 */
int c_list_len(CList *list)
{
    int res = 0;
    CList *tmp = list;
    if (list == NULL) {
        return 0;
    }
    while(tmp->next != NULL)
    {
        ++res;
        tmp = tmp->next;
    }
    return res;
}

/**
 * @brief 将单链表转换为数组
 * @param list 要转换的单链表
 * @return void** 成功则返回数组,失败返回NULL
 */
void **c_list_to_array(CList* list)
{
    int i;
    void **array;
    int n = c_list_len(list);
    if(n == 0)
        return NULL;

    CList* tmp = list->next;
    array = (void **)malloc(sizeof(*array) * (n+1));

    for(i=0;i<n;++i)
    {
        array[i] = tmp->val;
        tmp = tmp->next;
    }
    array[i] = NULL;

    return array;
}
