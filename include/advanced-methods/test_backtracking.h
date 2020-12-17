/***************************************************
* File:   backtracking.h
* Brief:
* Author: kate
* Update: 2020/12/17.
***************************************************/


#ifndef C_PRACTICE_TEST_BACKTRACKING_H
#define C_PRACTICE_TEST_BACKTRACKING_H

#include <string>
#include <vector>

class Backtracking {
public:
  /// @brief Find all forms of string s which can be converted to Ip address (Nowcoder 20)
  /// @param s : The input string
  /// @return Ip addresses
  static std::vector<std::string> restoreIpAddresses(std::string s);

  /// @brief Get all permutations of string S which contains repeat characters (letcode 08.08)
  /// @param S : Input string
  /// @return All permutations of S
  static std::vector<std::string> PermutationWithRepeatedCharacters(std::string S);

  /// @brief Get all permutations of string S which contains unique characters (letcode 08.08)
  /// @param S : Input string
  /// @return All permutations of S
  static std::vector<std::string> PermutationWithUniqueCharacters(std::string S);

private:
  /// @brief Find all forms of string s which can be converted to Ip address (Nowcoder 20)
  /// @param s : The input string
  /// @param start : Start index of current turn in s
  /// @param nums : Ip numbers
  /// @param result : Final Ips
  /// @param index : current turn
  static void get_ip_strings(std::string s, int start,
      std::vector<int> nums, std::vector<std::string> &result, int index);
};

#endif//C_PRACTICE_TEST_BACKTRACKING_H
