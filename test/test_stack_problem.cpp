/***************************************************
* File:   test_stack_problem.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "stack_problem_int.h"
#include <gtest/gtest.h>

TEST(StackProblem, constructMaximumBinaryTree) {
  StackProblem sl;
  BinaryTree bt;
  std::vector<int> vec{2,1,3,9,8,5,7,4};
  std::vector<int> result_vec;
  auto tr{sl.constructMaximumBinaryTree(vec)};
  bt.Traversal(tr, result_vec, BinaryTree::TraversalType::IN_ORDER);
  for (int i{0}; i < vec.size(); ++i) {
    ASSERT_EQ(vec.at(i), result_vec.at(i));
  }
}