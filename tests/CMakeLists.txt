add_executable(ds-test ds_test.c)
add_executable(cbasic cbasic.c)

target_link_libraries(
    ds-test PUBLIC
    wcl::ds
)

target_include_directories(
    ds-test PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${WECHAT_INCLUDE_DIR}"
    "${WECHAT_INCLUDE_DIR}/data_structures"
)
