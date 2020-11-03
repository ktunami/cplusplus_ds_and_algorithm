aux_source_directory(. SRC)
aux_source_directory(bit SRC_BIT)
aux_source_directory(data_structure/graph SRC_DATA_STRUCTURE_GRAPH)
aux_source_directory(data_structure/hash SRC_DATA_STRUCTURE_HASH)
aux_source_directory(data_structure/linear_structure SRC_DATA_STRUCTURE_LINEAR_STRUCTURE)
aux_source_directory(data_structure/tree SRC_DATA_STRUCTURE_TREE)
aux_source_directory(dp_dc SRC_DP_DC)
aux_source_directory(greedy SRC_GREEDY)
aux_source_directory(sort_search SRC_SORT_SEARCH)
aux_source_directory(string SRC_STRING)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

add_executable(c_prac
        ${SRC}
        ${SRC_BIT}
        ${SRC_DATA_STRUCTURE_GRAPH}
        ${SRC_DATA_STRUCTURE_HASH}
        ${SRC_DATA_STRUCTURE_LINEAR_STRUCTURE}
        ${SRC_DATA_STRUCTURE_TREE}
        ${SRC_DP_DC}
        ${SRC_GREEDY}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING} data_structure/linear_structure/statck_problem.cpp ../include/data_structure/tree/binary_tree.h data_structure/tree/binary_tree.cpp ../include/data_structure/linear_structure/queue_problem.h data_structure/linear_structure/queue_problem.cpp)

add_library(prac SHARED
        ${SRC}
        ${SRC_BIT}
        ${SRC_DATA_STRUCTURE_GRAPH}
        ${SRC_DATA_STRUCTURE_HASH}
        ${SRC_DATA_STRUCTURE_LINEAR_STRUCTURE}
        ${SRC_DATA_STRUCTURE_TREE}
        ${SRC_DP_DC}
        ${SRC_GREEDY}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING})

add_library(prac_static STATIC
        ${SRC}
        ${SRC_BIT}
        ${SRC_DATA_STRUCTURE_GRAPH}
        ${SRC_DATA_STRUCTURE_HASH}
        ${SRC_DATA_STRUCTURE_LINEAR_STRUCTURE}
        ${SRC_DATA_STRUCTURE_TREE}
        ${SRC_DP_DC}
        ${SRC_GREEDY}
        ${SRC_SORT_SEARCH}
        ${SRC_STRING})

set_target_properties(prac PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac_static PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac PROPERTIES VERSION 1.0 SOVERSION 1.1)