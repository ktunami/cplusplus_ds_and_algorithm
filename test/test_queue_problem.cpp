/***************************************************
* File:   test_queue_problem.cpp
* Brief:
* Author: kate
* Update: 2020/11/3.
***************************************************/

#include <gtest/gtest.h>

#include "common_test_method.h"
#include "queue_problem_int.h"


TEST(QueueProblem, maxSlidingWindow) {
  std::vector<int> data{4,3,5,4,3,3,6,7};
  std::vector<int> expected_result{5,5,5,4,6,7};
  int k = 3;
  QueueProblem qu;
  auto result{qu.maxSlidingWindow(data, k)};
  CheckIntVecEquality(expected_result,result);
}

TEST(QueueProblem, getNum) {
  std::vector<int> input_array{8,7,12,5,16,9,17,2,4,6};
  int num{4}, expected_result{14};
  QueueProblem qu;
  auto result{qu.getNum(input_array, num)};
  ASSERT_EQ(expected_result,result);
}
