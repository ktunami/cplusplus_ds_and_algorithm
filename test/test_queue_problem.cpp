/***************************************************
* File:   test_queue_problem.cpp
* Brief:
* Author: kate
* Update: 2020/11/3.
***************************************************/

#include "queue_problem_int.h"
#include <gtest/gtest.h>


TEST(QueueProblem, maxSlidingWindow) {
  std::vector<int> data{4,3,5,4,3,3,6,7};
  std::vector<int> expected_result{5,5,5,4,6,7};
  int k = 3;
  QueueProblem qu;
  auto result{qu.maxSlidingWindow(data, k)};
  ASSERT_EQ(expected_result.size(), result.size());
  for (int i{0}; i < result.size(); ++i) {
    ASSERT_EQ(result.at(i), expected_result.at(i));
  }
}

TEST(QueueProblem, getNum) {
  std::vector<int> input_array{8,7,12,5,16,9,17,2,4,6};
  int num{4}, expected_result{14};
  QueueProblem qu;
  auto result{qu.getNum(input_array, num)};
  ASSERT_EQ(expected_result,result);
}
