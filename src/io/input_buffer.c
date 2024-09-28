#include "io/input_buffer.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Create a input buffer object
 * @return InputBuffer*返回向内存申请的指针 
 */
InputBuffer *create_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    if(input_buffer == NULL)
        return NULL;
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

/**
 * @brief 从stdin中输入用户数据并将其保存在InputBuffer指针指向的
 * buffer字符串中,其他数据保存字符串的长度等数据
 * @param input_buffer 
 * @return int 成功返回0,否则返回-1
 */
int read_input(InputBuffer *input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
    if(bytes_read <= 0)
    {
        printf("Error reading input!\r\n");
        return -1;      // 出问题返回-1
    }
    input_buffer->input_length = bytes_read-1;
    input_buffer->buffer[input_buffer->input_length] = '\0';     // 丢掉最后一个\n字符
    return 0;       // 成功返回0
}

/**
 * @brief 释放InputBuffer指针(input_buffer)及其申请的字符串空间
 * @param input_buffer 
 */
void close_input_buffer(InputBuffer *input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}

/**
 * @brief 处理用户输入的元命令(meta_command)
 * @param input_buffer 
 * @return MetaCommandResult 返回处理之后的结果
 * @note 元命令都是以dot(.)作为第一个字符 
 */
MetaCommandResult do_meta_command(InputBuffer *input_buffer)
{
    // 1.退出系统的元命令:
    if(!strcmp(input_buffer->buffer, ".exit"))
    {
        exit(EXIT_SUCCESS);
    } else {
        // TODO: 暂时设置为未知元命令
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

/**
 * @brief 该simple database的"SQL Compiler",负责分析输入的命令是哪些,
 * 之后将命令交给executor对命令进行执行
 * @param input_buffer 输入的存储命令的指针
 * @param statement 保存输入命令的类型
 * @return PrepareResult 返回命令识别结果,方便之后根据结果进行命令执行
 * @note 将compiler和executor分开写是为了解耦和更好的扩展
 */
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement)
{
    // TODO: 目前只设置识别insert和select命令
    if(strncmp(input_buffer->buffer, "insert", 6) == 0) 
    {
        statement->type = STATEMENT_INSERT;
        // TODO: 处理insert的数据
        int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", 
            &(statement->row_to_insert.id), statement->row_to_insert.username, statement->row_to_insert.email);
            if (args_assigned < 3) {
                return PREPARE_SYNTAX_ERROR;
            }
        return PREPARE_SUCCESS;
    }
    if(strcmp(input_buffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

/**
 * @brief 将数据(存储在Statement语句类中)插入(执行的是insert命令)到表中
 * @param statement 
 * @param table 
 * @return ExecuteResult 执行结果
 * @note table->num_rows指的是当前表有多少行(Row)已经是被分配好的
 */
ExecuteResult execute_insert(Statement *statement, Table *table)
{
    if(table->num_rows >= TABLE_MAX_ROWS)
    {
        return EXECUTE_TABLE_FULL;
    }
    Row *row_to_insert = &(statement->row_to_insert);
    serialize_row(row_to_insert, row_slot(table, table->num_rows));
    table->num_rows += 1;
    return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement *statement, Table *table)
{
    Row row;
    // !这里暂时选择将全部数据打印出来
    for(int i=0;i<table->num_rows;++i)
    {
        deserialize_row(row_slot(table, i), &row);
        // 将查询结果打印出来:
        print_row(&row);
    }
    return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement *statement, Table *table)
{
    switch (statement->type) {
        case STATEMENT_INSERT:
        {
            return execute_insert(statement, table);
        }
        case STATEMENT_SELECT:
        {
            return execute_select(statement, table);
        }
        default:
            printf("Unrecognized statement!");
    }
    return EXECUTE_SUCCESS;
}
