/***************************************************
* File:   backtracking.cpp
* Brief:
* Author: kate
* Update: 2020/12/17.
***************************************************/

#include <gtest/gtest.h>

#include "backtracking_int.h"
#include "common_test_method.h"

TEST(Backtracking, restoreIpAddresses) {
  std::string s = "25525511135";
  auto str_vec{Backtracking::restoreIpAddresses(s)};
  std::vector<std::string> result{"255.255.11.135","255.255.111.35"};
  CheckStringVecEquality(str_vec, result);
  std::string s1 = "010010";
  auto str_vec1{Backtracking::restoreIpAddresses(s1)};
  std::vector<std::string> result1{"0.10.0.10", "0.100.1.0"};
  CheckStringVecEquality(str_vec1, result1);
}

TEST(Backtracking, PermutationWithRepeatedCharacters) {
  std::string s = "qqe";
  auto str_vec{Backtracking::PermutationWithRepeatedCharacters(s)};
  std::vector<std::string> result{"eqq","qeq","qqe"};
  CheckStringVecEquality(str_vec, result);
}

TEST(Backtracking, PermutationWithUniqueCharacters) {
  std::string s = "qwe";
  auto str_vec{Backtracking::PermutationWithRepeatedCharacters(s)};
  std::vector<std::string> result{"eqw", "ewq", "qew", "qwe", "weq", "wqe"};
  CheckStringVecEquality(str_vec, result);
}