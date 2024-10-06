#pragma once
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>


#define create_type_array(Struct, Type, Size) (Struct->array = (Type*)malloc(sizeof(Type)*Size))
#define create_array(Struct, Type, Size) \
{\
    Struct *carr = (Struct *)malloc(sizeof(Struct));\
    if(carr == NULL) return NULL;\
    carr->array = (Type*)malloc(sizeof(Type)*Size);\
    if(carr->array == NULL) {free(car); return NULL;}\
    return carr;\
}

typedef struct {
    uint32_t len;       // 数组的当前长度
    void *array;
}CArray;
