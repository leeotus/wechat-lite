#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdint.h>
#include "table.h"

// definitions for commands and statement

// tips: 由于C不支持C++那样的exception异常抛出.所以这里使用enum来制定各种状态
typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
}MetaCommandResult;

typedef enum {
    PREPARE_SYNTAX_ERROR=-1,
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

// 判断各种sql语句
typedef enum {
    STATEMENT_UNRECOGNIZED = -1,
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

// 命令操作状态
typedef enum {
    EXECUTE_TABLE_FULL = -1,
    EXECUTE_SUCCESS = 0,
} ExecuteResult;

typedef struct {
    StatementType type;
    Row row_to_insert;
} Statement;

#endif