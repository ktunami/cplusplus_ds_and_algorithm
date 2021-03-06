/***************************************************
* File:   common_test_method.cpp
* Brief:  Common functions for gtest
* Author: kate
* Update: 2020/11/14.
***************************************************/

#include <gtest/gtest.h>
#include <unordered_set>

#include "common_test_method.h"

void CheckIntVecEquality(std::vector<int> const& vec1, std::vector<int> const& vec2) {
  ASSERT_EQ(vec1.size(), vec2.size());
  for (int i{0}; i < vec1.size(); ++i) {
    EXPECT_EQ(vec1.at(i), vec2.at(i));
  }
}

void Check2DIntVecEquality(std::vector<std::vector<int>> const& vec1, std::vector<std::vector<int>> const& vec2) {
  ASSERT_EQ(vec1.size(), vec2.size());
  for (int i{0}; i < vec1.size(); ++i) {
    CheckIntVecEquality(vec1.at(i), vec2.at(i));
  }
}

void CheckStringVecEqualityStrict(std::vector<std::string> const& vec1, std::vector<std::string> const& vec2) {
  ASSERT_EQ(vec1.size(), vec2.size());
  for (int i{0}; i < vec1.size(); ++i) {
    ASSERT_EQ(vec1.at(i), vec2.at(i));
  }
}

void CheckStringVecEqualityUnStrict(std::vector<std::string> const& vec1, std::vector<std::string> const& vec2) {
  ASSERT_EQ(vec1.size(), vec2.size());
  std::unordered_set<std::string> str_set;
  for (auto const& str : vec1) {
    str_set.insert(str);
  }
  for (auto const& str : vec1) {
    ASSERT_FALSE(str_set.find(str) == str_set.end());
  }
}

void PrintIntVector(std::vector<int> const & vec) {
  static int j = 1;
  std::cout << "group : " << j << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << "--";
  }
  std::cout << std::endl;
  ++j;
}

void PrintStingVector(std::vector<std::string> const& vec) {
  std::cout << "Begin to print strings: " << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << std::endl;
  }
}


void Print2DVector(std::vector<std::vector<int>> const& vec) {
  std::cout << "Begin to print the 2D vector is: " << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    PrintIntVector(vec.at(i));
  }
  std::cout << "2D vector print over " << std::endl;
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

void Check2DSameMembers(
    std::vector<std::vector<int>> & vec1,
    std::vector<std::vector<int>> & vec2,
    bool need_sort) {
  ASSERT_EQ(vec1.size(), vec2.size());
  std::unordered_set<long long> st;
  for (int i{0}; i < vec1.size(); ++i) {
    if (need_sort) {
      std::sort(vec1.at(i).begin(), vec1.at(i).end());
      std::sort(vec2.at(i).begin(), vec2.at(i).end());
    }
    st.insert(RSHashForVector(vec1.at(i)));
  }
  for (int i{0}; i < vec1.size(); ++i) {
    ASSERT_FALSE(st.find(RSHashForVector(vec2.at(i))) == st.end());
  }
}