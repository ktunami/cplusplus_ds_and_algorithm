aux_source_directory(. SRC)
aux_source_directory(others SRC_OTHERS)
aux_source_directory(divide-conquer SRC_DIVIDED_CONQUER)
aux_source_directory(dynamic-programming SRC_DYNAMIC_PROGRAMMING)
aux_source_directory(greedy SRC_GREEDY)
aux_source_directory(linear-structure SRC_LINEAR_STRUCTURE)
aux_source_directory(sort_search SRC_SORT_SEARCH)
aux_source_directory(string SRC_STRING)
aux_source_directory(tree-graph SRC_TREE_GRAPH)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

add_executable(c_prac
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_DIVIDED_CONQUER}
        ${SRC_DYNAMIC_PROGRAMMING}
        ${SRC_GREEDY}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING}
        ${SRC_TREE_GRAPH})


add_library(prac SHARED
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_DIVIDED_CONQUER}
        ${SRC_DYNAMIC_PROGRAMMING}
        ${SRC_GREEDY}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING}
        ${SRC_TREE_GRAPH})

add_library(prac_static STATIC
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_DIVIDED_CONQUER}
        ${SRC_DYNAMIC_PROGRAMMING}
        ${SRC_GREEDY}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING}
        ${SRC_TREE_GRAPH})

set_target_properties(prac PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac_static PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac PROPERTIES VERSION 1.0 SOVERSION 1.1)