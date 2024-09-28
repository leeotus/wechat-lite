cmake_minimum_required(VERSION 3.10.0)

set(WECHAT_TARGET_NAME "wechat-lite")
project(${WECHAT_TARGET_NAME} VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 17)

set(WECHAT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")

add_subdirectory(src)

option(BUILD_APPS "build application with this library." ON)
if(BUILD_APPS)
    add_subdirectory(apps)
endif()

option(ENABLE_TESTS "enable test for this library." OFF)
if(ENABLE_TESTS) 
    add_subdirectory(tests)
endif()