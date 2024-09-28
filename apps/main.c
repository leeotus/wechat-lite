#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "cs_defs.h"
#include "table.h"
#include "io/input_buffer.h"

#define INPUT_ERROR -1
#define SUCCESSFULLY_EXIT 0

void print_prompt();

int main(int argc, char **argv)
{
    int res;
    Table *table = create_new_table();
    InputBuffer* input_buffer = create_input_buffer();
    while(true)
    {
        print_prompt();
        res = read_input(input_buffer);
        if(res == -1)
            exit(INPUT_ERROR);

        if(input_buffer->buffer[0] == '.') {
            // switch to meta-commands.
            switch (do_meta_command(input_buffer)) {
                case (META_COMMAND_SUCCESS):
                {
                    // TODO: 除了.exit其他的元命令还没有设置
                    continue;
                }
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                {
                    printf("unrecognized meta_command!\r\n");
                    continue;
                }
            }
        }
        
        // switch to common commands:
        // sql compiler
        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
            {
                break;
            }
            case (PREPARE_STRING_TOO_LANG):
            {
                printf("Input string is too long.\r\n");
                continue;
            }
            case (PREPARE_NEGATIVE_NUMBER):
            {
                printf("id must positive!\r\n");
                continue;
            }
            case (PREPARE_SYNTAX_ERROR):
            {
                // ?目前只有insert语句出错时候报这个错误
                printf("Synax error. Could not parse statement.\r\n");
                continue;
            }
            case (PREPARE_UNRECOGNIZED_STATEMENT):
            {
                printf("unrecognized statement!\r\n");
                continue;
            }
        }

        // executor:
        switch (execute_statement(&statement, table)) {
            case (EXECUTE_SUCCESS):
            {
                printf("Executed.\r\n");
                break;
            }
            case (EXECUTE_TABLE_FULL):
            {
                printf("Error: Table full.\r\n");
                break;
            }
        }

    }
    return 0;
}

void print_prompt() { printf("db > "); }
