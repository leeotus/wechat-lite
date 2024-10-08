#include <stdio.h>
#include <unistd.h>
#include "stack/c_stack.h"

int main(int argc, char **argv)
{
    cstack *cs = cstack_init();
    int num1 = 10;
    int *num2;
    cstack_push(cs, (void *)&num1);
    for(int i=0;i<25;++i)
    {
        // test for mempool:
        cstack_push(cs, (void *)&num1);
    }
    cstack_pop(cs, (void**)&num2);
    printf("str2=%d\r\n", *num2);
    return 0;
}
