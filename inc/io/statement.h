#pragma once

#include "types.h"
#include "table.h"

typedef struct {
    StatementType type;                 // 记录命令类型
    Row row_to_insert;                  // 记录命令所附带的行数据
} Statement;

