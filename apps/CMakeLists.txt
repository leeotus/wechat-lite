add_executable(${WECHAT_TARGET_NAME} main.c)

target_link_libraries(${WECHAT_TARGET_NAME} PRIVATE wcl::core)
target_include_directories(${WECHAT_TARGET_NAME} PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${WECHAT_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src"
)
