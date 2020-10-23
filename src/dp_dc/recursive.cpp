//
// Created by kate on 2020/10/21.
//

#include "dp_dc/recursive.h"

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