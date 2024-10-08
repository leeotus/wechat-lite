set(DS_TARGET_NAME ${WECHAT_TARGET_NAME}-ds)

add_library(
    ${DS_TARGET_NAME}
    ${WECHAT_INCLUDE_DIR}/data_structures/queue/c_queue.h
    ${WECHAT_INCLUDE_DIR}/data_structures/queue/c_memqueue.h
    ${WECHAT_INCLUDE_DIR}/data_structures/stack/c_stack.h
    ${WECHAT_INCLUDE_DIR}/data_structures/list/c_list.h
    ${WECHAT_INCLUDE_DIR}/data_structures/binary_tree/bt_node.h
    ${WECHAT_INCLUDE_DIR}/data_structures/binary_tree/bt_mem_node.h
    ${WECHAT_INCLUDE_DIR}/data_structures/mem_pool/mempool.h
    list/c_list.c
    queue/c_queue.c
    queue/c_memqueue.c
    stack/c_stack.c
    binary_tree/bt_node.c
    binary_tree/bt_memqueue.c
    mem_pool/mempool.c
)

message("in ds cmake: WECHAT_INCLUDE_DIR = ${WECHAT_INCLUDE_DIR}")

target_include_directories(
    ${DS_TARGET_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${WECHAT_INCLUDE_DIR}/data_structures
)

add_library(wcl::ds ALIAS ${DS_TARGET_NAME})

set_target_properties(
    ${DS_TARGET_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    EXPORT_NAME ds
)
