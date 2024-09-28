#ifndef __C_LIST_H__
#define __C_LIST_H__

typedef struct _c_list {
    void *val;
    struct _c_list* next;
}CList;

int c_list_init(CList *list);
int c_list_push(CList *list, void *val);
int c_list_len(CList *list);

void **c_list_to_array(CList *list);

#endif
