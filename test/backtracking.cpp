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
  CheckStringVecEqualityUnStrict(str_vec, result);
  std::string s1 = "010010";
  auto str_vec1{Backtracking::restoreIpAddresses(s1)};
  std::vector<std::string> result1{"0.10.0.10", "0.100.1.0"};
  CheckStringVecEqualityUnStrict(str_vec1, result1);
}

TEST(Backtracking, PermutationWithRepeatedCharacters) {
  std::string s = "qqe";
  auto str_vec{Backtracking::PermutationWithRepeatedCharacters(s)};
  std::vector<std::string> result{"eqq","qeq","qqe"};
  CheckStringVecEqualityUnStrict(str_vec, result);
}

TEST(Backtracking, PermutationWithUniqueCharacters) {
  std::string s = "qwe";
  auto str_vec{Backtracking::PermutationWithUniqueCharacters(s)};
  std::vector<std::string> result{"eqw", "ewq", "qew", "qwe", "weq", "wqe"};
  CheckStringVecEqualityUnStrict(str_vec, result);
  auto str_vec2{Backtracking::PermutationWithUniqueCharacters2(s)};
  std::cout << std::endl <<std::endl;
  CheckStringVecEqualityUnStrict(str_vec2, result);
}

TEST(Backtracking, combinationSum) {
  std::vector<int> input{10,1,2,7,6,1,5};
  int target{8};
  std::vector<std::vector<int>> expected_result{
    {1,1,6}, {1,2,5}, {1,7}, {2,6}
  };
  auto result1{Backtracking::combinationSum1(input, target)};
  Check2DSameMembers(result1, expected_result, true);
  auto result2{Backtracking::combinationSum2(input, target)};
  Check2DSameMembers(result2, expected_result, true);
}

TEST(Backtracking, solveNQueens) {
  auto str_vec{Backtracking::solveNQueens(4)};
  std::vector<std::vector<std::string>> result{
    {".Q..","...Q","Q...","..Q."},
    {"..Q.","Q...","...Q",".Q.."}
  };
  ASSERT_EQ(str_vec.size(), result.size());
  for (int i{0}; i < result.size(); ++i) {
    CheckStringVecEqualityUnStrict(result.at(i), str_vec.at(i));
  }
}