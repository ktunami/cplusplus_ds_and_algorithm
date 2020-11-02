/***************************************************
* File:   test_recursive.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "recursive_int.h"
#include <gtest/gtest.h>
#include <ctime>

TEST(Recursive, ReverseStack){
  std::stack<int> st,st1,st2;
  int num = 5;
  for (int i = 0; i < num; i++) {
    int tmp = std::rand();
    if (i != 0) {
      EXPECT_FALSE(st.top() == tmp);
    }
    st.push(tmp);
    st1.push(tmp);
  }
  Recursive rc;
  rc.ReverseStack(st);
  while(!st.empty()) {
    st2.push(st.top());
    st.pop();
  }
  while ((!st1.empty()) && (!st2.empty())) {
    ASSERT_EQ(st1.top(), st2.top());
    st1.pop();
    st2.pop();
  }
  ASSERT_TRUE(st1.empty());
  ASSERT_TRUE(st2.empty());
}