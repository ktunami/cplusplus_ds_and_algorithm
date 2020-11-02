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
  void ReverseStack(std::stack<int> &st);
  int get_bottom_num(std::stack<int> &st);
};
#endif//C_PRACTICE_RECURSIVE_H_INT
