cmake_minimum_required(VERSION 3.16)
project(c_practice)
add_definitions("-Wall -g")
set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/bitwise-operation
        ${PROJECT_SOURCE_DIR}/include/dynamic-programming
        ${PROJECT_SOURCE_DIR}/include/greedy
        ${PROJECT_SOURCE_DIR}/include/linear-structure
        ${PROJECT_SOURCE_DIR}/include/sort-search
        ${PROJECT_SOURCE_DIR}/include/string
        ${PROJECT_SOURCE_DIR}/include/tree-graph
        ${PROJECT_SOURCE_DIR}/include/divide-conquer
        ${PROJECT_SOURCE_DIR}/test/include
        /usr/local/include
)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)
