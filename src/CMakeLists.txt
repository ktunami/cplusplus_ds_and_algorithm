aux_source_directory(. SRC)
aux_source_directory(others SRC_OTHERS)
aux_source_directory(advanced-methods SRC_ADVANCED_METHODS)
aux_source_directory(linear-structure SRC_LINEAR_STRUCTURE)
aux_source_directory(sort-search SRC_SORT_SEARCH)
aux_source_directory(tree-graph SRC_TREE_GRAPH)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib)

add_executable(c_prac
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_ADVANCED_METHODS}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_TREE_GRAPH})


add_library(prac SHARED
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_ADVANCED_METHODS}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_TREE_GRAPH})

add_library(prac_static STATIC
        ${SRC}
        ${SRC_OTHERS}
        ${SRC_ADVANCED_METHODS}
        ${SRC_LINEAR_STRUCTURE}
        ${SRC_SORT_SEARCH}
        ${SRC_TREE_GRAPH})

set_target_properties(prac PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac_static PROPERTIES OUTPUT_NAME "libprac")
set_target_properties(prac PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(prac PROPERTIES VERSION 1.0 SOVERSION 1.1)