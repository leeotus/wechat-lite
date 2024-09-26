#include <stdio.h>
#include "io/input_buffer.h"

void print_prompt();

int main(int argc, char **argv)
{
    InputBuffer* input_buffer = create_input_buffer();
    printf("create input_buffer successfully!\r\n");
    return 0;
}

void print_prompt() { printf("db > "); }
