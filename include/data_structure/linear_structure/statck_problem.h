/***************************************************
* File:   stack_problem.h
* Brief:  Solutions by applying stack
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_STATCK_PROBLEM_H
#define C_PRACTICE_STATCK_PROBLEM_H

#include "data_structure/tree/binary_tree.h"
#include <stack>
#include <vector>

class StackProblem {
public:
  /// @brief  Create MaxTree from nums (Leetcode 654)
  /// @return Root of MaxTree
  BTNode* constructMaximumBinaryTree(std::vector<int>& nums);


  /// @brief Daily Temperature (leetcode 739)
  /// @param T : Input temperatures
  /// @return Vector of days for a rise
  std::vector<int> dailyTemperatures(std::vector<int>& T);

  /// @brief Largest rectangle area (leetcode 84)
  /// @param heights : Input rectangle heights
  /// @return Largest rectangle area
  int largestRectangleArea(std::vector<int>& heights);

  /// @brief Max rectangle problem (leetcode 85)
  /// @param matrix : Input matrix
  /// @return Largest matrix points num (should be all ones)
  int maximalRectangle(std::vector<std::vector<char>>& matrix);

};

#endif//C_PRACTICE_STATCK_PROBLEM_H
