/***************************************************
* File:   recursive.h
* Brief:  Solutions by applying recursive method
* Author: kate
* Update: 2020/10/25.
***************************************************/


#ifndef C_PRACTICE_RECURSIVE_H
#define C_PRACTICE_RECURSIVE_H
#include <stack>

class Recursive{
public:
  void ReverseStack(std::stack<int> &st);
private:
  int get_bottom_num(std::stack<int> &st);
};
#endif//C_PRACTICE_RECURSIVE_H