/***************************************************
* File:   dynamic_programming_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/12/26.
***************************************************/


#ifndef C_PRACTICE_DYNAMIC_PROGRAMMING_INT_H
#define C_PRACTICE_DYNAMIC_PROGRAMMING_INT_H

#include <vector>

class DProAlgo{
public:
  ///@brief Compute fibonacci number (O(n))
  static int FibonacciNum1(int n);

  ///@brief Compute fibonacci number (O(log n))
  static int FibonacciNum2(int n);

  /// @brief Climb stairs (leetcode 70)
  static int climbStairs(int n);

  /// @brief Maximum Subarray (leetcode 53)
  static int maxSubArray(std::vector<int>& nums);

  /// @brief Longest Increasing Subsequence  (leetcode 300)
  static int lengthOfLIS(std::vector<int>& nums);

  /// @brief Given a triangle array, return the minimum path sum from top to bottom.
  static int minimumTotal(std::vector<std::vector<int>>& triangle);
};

#endif//C_PRACTICE_DYNAMIC_PROGRAMMING_INT_H
