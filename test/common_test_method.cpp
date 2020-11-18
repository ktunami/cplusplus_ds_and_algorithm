/***************************************************
* File:   common_test_method.cpp
* Brief:  Common functions for gtest
* Author: kate
* Update: 2020/11/14.
***************************************************/

#include "common_test_method.h"
#include <gtest/gtest.h>

void CheckIntVecEquality(std::vector<int> &vec1, std::vector<int> &vec2) {
  ASSERT_EQ(vec1.size(), vec2.size());
  for (int i{0}; i < vec1.size(); ++i) {
    ASSERT_EQ(vec1.at(i), vec2.at(i));
  }
}

void PrintVector(std::vector<int> &vec) {
  static int j = 1;
  std::cout << "group : " << j << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << "--";
  }
  std::cout << std::endl;
  ++j;
}

long long RSHashForVector(std::vector<int> const& vec) {
  long long b  = 378551;
  long long a  = 63689;
  long long hash = 0;
  for(int i = 0; i < vec.size(); i++) {
    hash = hash * a + vec.at(i);
    a  = a * b;
  }
  return hash;
}
