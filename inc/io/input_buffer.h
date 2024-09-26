#ifndef __INPUT_BUFFER__

#define __INPUT_BUFFER__

#include <stdio.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
}InputBuffer;

InputBuffer *create_input_buffer();

#endif