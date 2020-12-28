/***************************************************
* File:   test_dynamic_programming.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/12/26.
***************************************************/

#include <gtest/gtest.h>

#include "dynamic_programming_int.h"


TEST(DProAlgo, FibonacciNum1) {
  ASSERT_EQ(0,DProAlgo::FibonacciNum1(0));
  ASSERT_EQ(1,DProAlgo::FibonacciNum1(1));
  ASSERT_EQ(1,DProAlgo::FibonacciNum1(2));
  ASSERT_EQ(2,DProAlgo::FibonacciNum1(3));
  ASSERT_EQ(13,DProAlgo::FibonacciNum1(7));
}

TEST(DProAlgo, FibonacciNum2) {
  ASSERT_EQ(0,DProAlgo::FibonacciNum2(0));
  ASSERT_EQ(1,DProAlgo::FibonacciNum2(1));
  ASSERT_EQ(1,DProAlgo::FibonacciNum2(2));
  ASSERT_EQ(2,DProAlgo::FibonacciNum2(3));
  ASSERT_EQ(13,DProAlgo::FibonacciNum2(7));
}

TEST(DProAlgo, climbStairs) {
  ASSERT_EQ(1,DProAlgo::climbStairs(1));
  ASSERT_EQ(2,DProAlgo::climbStairs(2));
  ASSERT_EQ(5,DProAlgo::climbStairs(4));
}

TEST(DProAlgo, maxSubArray) {
  std::vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
  ASSERT_EQ(6,DProAlgo::maxSubArray(input));
}

TEST(DProAlgo, lengthOfLIS) {
  std::vector<int> input{0};
  ASSERT_EQ(1,DProAlgo::lengthOfLIS(input));
  std::vector<int> input2{1,9,5,9,3};
  ASSERT_EQ(3,DProAlgo::lengthOfLIS(input2));
}

