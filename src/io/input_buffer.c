#include "io/input_buffer.h"
#include <stdlib.h>

InputBuffer *create_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    if(input_buffer == NULL)
        return NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}
