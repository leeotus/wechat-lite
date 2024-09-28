set(DS_TARGET_NAME ${WECHAT_TARGET_NAME}-ds)

add_library(
    ${DS_TARGET_NAME}
    list/c_list.c
    ${WECHAT_INCLUDE_DIR}/data_structures/list/c_list.h
)

message("in ds cmake: WECHAT_INCLUDE_DIR = ${WECHAT_INCLUDE_DIR}")

target_include_directories(
    ${DS_TARGET_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${WECHAT_INCLUDE_DIR}/data_structures
)

add_library(wcl-ds ALIAS ${DS_TARGET_NAME})

set_target_properties(
    ${DS_TARGET_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    EXPORT_NAME ds
)
