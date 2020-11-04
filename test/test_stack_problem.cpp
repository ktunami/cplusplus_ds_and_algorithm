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

TEST(StackProblem, dailyTemperatures) {
  StackProblem sl;
  std::vector<int> vec{73,74,75,71,69,72,76,73};
  std::vector<int> expected_result{1,1,4,2,1,1,0,0};
  auto result{sl.dailyTemperatures(vec)};
  ASSERT_EQ(result.size(), expected_result.size());
  for (int i{0}; i < vec.size(); ++i) {
    ASSERT_EQ(result.at(i), expected_result.at(i));
  }
}

TEST(StackProblem, largestRectangleArea) {
  StackProblem sl;
  std::vector<int> vec{2,1,5,6,2,3};
  int expected_result{10};
  ASSERT_EQ(expected_result, sl.largestRectangleArea(vec));
}

TEST(StackProblem, maximalRectangle) {
  StackProblem sl;
  std::vector<std::vector<char>> input {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
  };
  int expected_result{6};
  ASSERT_EQ(expected_result, sl.maximalRectangle(input));
}