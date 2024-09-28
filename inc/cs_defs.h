#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdint.h>
#include "table.h"

// definitions for commands and statement

// tips: 由于C不支持C++那样的exception异常抛出.所以这里使用enum来制定各种状态
typedef enum {
    META_COMMAND_SUCCESS,               // 元命令执行成功
    META_COMMAND_UNRECOGNIZED_COMMAND   // 元命令未识别成功
}MetaCommandResult;

typedef enum {
    PREPARE_SYNTAX_ERROR=-1,            // 解析失败:原因是语法错误
    PREPARE_SUCCESS,                    // 解析成功
    PREPARE_UNRECOGNIZED_STATEMENT,     // 解析失败:原因是未知命令
    PREPARE_STRING_TOO_LANG,            // 解析失败:原因是输入字符串过长
    PREPARE_NEGATIVE_NUMBER,            // 解析失败:原因是输入的数字为负数,有些数据要求必须要正数
} PrepareResult;

// 判断各种sql语句
typedef enum {
    STATEMENT_UNRECOGNIZED = -1,        // 未识别出命令类型
    STATEMENT_INSERT,                   // 识别出命令类型为insert
    STATEMENT_SELECT                    // 识别出命令类型为select
} StatementType;

// 命令操作状态
typedef enum {
    EXECUTE_TABLE_FULL = -1,            // 运行命令失败:原因是数据表已满
    EXECUTE_SUCCESS = 0,                // 执行命令成功
} ExecuteResult;

typedef struct {
    StatementType type;                 // 记录命令类型
    Row row_to_insert;                  // 记录命令所附带的行数据
} Statement;

#endif