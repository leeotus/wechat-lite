#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
    uint32_t len;       // 数组的当前长度
    void *array;
}CArray;

#define create_type_array(Struct, Type, Size) (Struct->array = (Type*)malloc(sizeof(Type)*Size))

#define ai_create_array(Struct, Type, Size) \
({ \
    Struct *carr = (Struct *)malloc(sizeof(Struct)); \
    if (carr == NULL) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(EXIT_FAILURE); \
    } \
    carr->array = (Type *)malloc(sizeof(Type) * Size); \
    if (carr->array == NULL) { \
        free(carr); \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(EXIT_FAILURE); \
    } \
    return carr; \
})

#define create_some_things(Type, Size) ((Type*)malloc(sizeof(Type)*Size))
#define malloc_type_array(Object, Type, Size) (Object->array = create_some_things(Type, Size))  

int main(int argc, char **argv)
{
    CArray *arr = (CArray*)malloc(sizeof(CArray));
    malloc_type_array(arr, int, 10);
    return 0;
}