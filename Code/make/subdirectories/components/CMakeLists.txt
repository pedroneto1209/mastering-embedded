add_library(
    log
    log/log.hpp
    log/log.cpp
)

target_include_directories(log PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_definitions(log PUBLIC SAY_HELLO_VERSION=5)