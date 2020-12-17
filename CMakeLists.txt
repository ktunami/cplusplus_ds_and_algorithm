cmake_minimum_required(VERSION 3.16)
project(c_practice)
add_definitions("-Wall -g")
set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/others
        ${PROJECT_SOURCE_DIR}/include/linear-structure
        ${PROJECT_SOURCE_DIR}/include/sort-search
        ${PROJECT_SOURCE_DIR}/include/tree-graph
        ${PROJECT_SOURCE_DIR}/include/advanced-methods
        ${PROJECT_SOURCE_DIR}/test/include
        /usr/local/include
)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)
