/***************************************************
* File:   backtracking_int.h
* Brief:
* Author: kate
* Update: 2020/12/17.
***************************************************/


#ifndef C_PRACTICE_BACKTRACKING_INT_H
#define C_PRACTICE_BACKTRACKING_INT_H

#include <string>
#include <vector>

class Backtracking {
public:

  /// @brief Find all forms of string s which can be converted to Ip address (Nowcoder 20)
  /// @param s : The input string
  /// @param start : Start index of current turn in s
  /// @param nums : Ip numbers
  /// @param result : Final Ips
  /// @param index : current turn
  static void get_ip_strings(std::string s, int start,
      std::vector<int> nums, std::vector<std::string> &result, int index);

  /// @brief Find all forms of string s which can be converted to Ip address (Nowcoder 20)
  /// @param s : The input string
  /// @return Ip addresses
  static std::vector<std::string> restoreIpAddresses(std::string s);

  /// @brief Get all permutations of string S which contains repeat characters (leetcode 08.08)
  /// @param S : Input string
  /// @return All permutations of S
  static std::vector<std::string> PermutationWithRepeatedCharacters(std::string S);

  /// @brief Get all permutations of string S which contains unique characters (leetcode 08.07)
  /// @param S : Input string
  /// @return All permutations of S
  static std::vector<std::string> PermutationWithUniqueCharacters(std::string S);

  /// @brief Get all permutations of string S which contains unique characters (leetcode 08.07)
  /// https://www.cnblogs.com/songchengyu/p/12640126.html
  /// @param S : Input string
  /// @return All permutations of S
  static std::vector<std::string> PermutationWithUniqueCharacters2(std::string S);

  /// @brief Get all subsets that add up to a target number (leetcode 40)
  /// @param num : Input vector
  /// @param target : The target number
  /// @return All combinations
  static std::vector<std::vector<int> > combinationSum1(std::vector<int> &candidates, int target);

  /// @brief Get all subsets that add up to a target number (leetcode 40)
  /// @param num : Input vector
  /// @param target : The target number
  /// @return All combinations
  static std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target);

  /// @brief N queens problem (leetcode 51)
  static std::vector<std::vector<std::string>> solveNQueens(int n);
};


#endif//C_PRACTICE_BACKTRACKING_INT_H
