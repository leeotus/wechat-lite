#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
    int num;
}Msg;

void just_for_test(void *msg)
{
    ((Msg*)msg)->num = 12;
    return;
}

int main(int argc, char **argv)
{
    Msg *msg1 = (Msg *)malloc(sizeof(Msg));
    msg1->num = 10;
    printf("msg->num:%d\r\n", msg1->num);
    just_for_test(msg1);
    printf("msg->num:%d\r\n", msg1->num);
    return 0;
}
