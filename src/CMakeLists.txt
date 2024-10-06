set(SUBLIB_NAME "wcl")

message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
    ${SUBLIB_NAME}
    ${WECHAT_INCLUDE_DIR}/table.h
    ${WECHAT_INCLUDE_DIR}/defs.h
    ${WECHAT_INCLUDE_DIR}/types.h
    ${WECHAT_INCLUDE_DIR}/io/statement.h
    ${WECHAT_INCLUDE_DIR}/io/input_buffer.h
    ${WECHAT_INCLUDE_DIR}/io/pager.h
    io/input_buffer.c
    io/pager.c
    table.c
)

target_include_directories(${SUBLIB_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${WECHAT_INCLUDE_DIR}"
)

add_library(wcl::core ALIAS ${SUBLIB_NAME})
set_target_properties(${SUBLIB_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    EXPORT_NAME core
    LINKER_LANGUAGE CXX
)

add_subdirectory(data_structures)
