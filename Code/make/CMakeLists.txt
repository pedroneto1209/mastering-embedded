cmake_minimum_required(VERSION 3.27)
project(testProject VERSION 1.0.0)

add_library(
    log
    log.hpp
    log.cpp
)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE log)