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
  std::string s1 = "010010";
  auto str_vec1{Backtracking::restoreIpAddresses(s1)};

}

TEST(Backtracking, PermutationWithRepeatedCharacter) {
  std::string s = "qqe";
  auto str_vec{Backtracking::PermutationWithRepeatedCharacter(s)};
  PrintStingVector(str_vec);

}