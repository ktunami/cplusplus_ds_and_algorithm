/***************************************************
* File:   recursive.cpp
* Brief:  Solutions by applying recursive method
* Author: kate
* Update: 2020/10/25.
***************************************************/

#include "recursive.h"

void Recursive::ReverseStack(std::stack<int> &st) {
  if (!st.empty()) {
    int btm = get_bottom_num(st);
    ReverseStack(st);
    st.push(btm);
  }
}

int Recursive::get_bottom_num(std::stack<int> &st) {
  int tp = st.top();
  st.pop();
  if (st.empty()) {
    return tp;
  } else {
    int lst = get_bottom_num(st);
    st.push(tp);
    return lst;
  }
}

int Recursive::PowNum(int m, int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return m;
  } else {
    int k = n >> 1;
    auto half{PowNum(m, k)};
    if (n % 2 == 1) {
      return half * half * m;
    } else {
      return half * half;
    }
  }
}