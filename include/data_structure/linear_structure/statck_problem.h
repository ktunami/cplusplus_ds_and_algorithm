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
};

#endif//C_PRACTICE_STATCK_PROBLEM_H
