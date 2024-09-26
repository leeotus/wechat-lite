add_executable(main-test main.c)

target_link_libraries(main-test PRIVATE wcl::core)
target_include_directories(main-test PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${WECHAT_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src"
)
