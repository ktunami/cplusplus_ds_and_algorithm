/***************************************************
* File:   recursive_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_RECURSIVE_H_INT
#define C_PRACTICE_RECURSIVE_H_INT
#include <stack>

class Recursive{
public:

  /// @brief Get the bottom element from stack
  /// @param st : The stack to be operated
  /// @return The bottom element in the stack
  static int get_bottom_num(std::stack<int> &st);

  /// @brief Reverse a stack inplace
  /// @param st : The stack to be operated
  static void ReverseStack(std::stack<int> &st);

  /// @brief Exponent arithmetic
  /// @param m : Base number
  /// @param n : Exponent
  /// @return Result of m^n
  static int PowNum(int m, int n);

};
#endif//C_PRACTICE_RECURSIVE_H_INT
