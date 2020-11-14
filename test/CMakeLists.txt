aux_source_directory(${PROJECT_SOURCE_DIR}/test DIRSRCS)
enable_testing()
find_package(GTest REQUIRED)
add_executable(test-prac ${DIRSRCS} test_stack_problem.cpp include/queue_problem_int.h test_queue_problem.cpp test_binary_tree.cpp)
target_link_libraries(
        test-prac GTest::GTest GTest::Main prac
)
add_test(NAME PracTest COMMAND test-prac)