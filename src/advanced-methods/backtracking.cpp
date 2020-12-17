/***************************************************
* File:   backtracking.cpp
* Brief:
* Author: kate
* Update: 2020/12/17.
***************************************************/

#include "test_backtracking.h"

#include <iostream>


void Backtracking::get_ip_strings(std::string s, int start,
    std::vector<int> nums, std::vector<std::string> &result, int index) {
  if (index == 4) {
    if (start == s.size()) {
      std::string ip;
      for (int i{0}; i < 4; ++i) {
        ip += std::to_string(nums.at(i));
        if (i < 3) {
          ip += ".";
        }
      }
      result.push_back(ip);
    }
  } else {
    if (start < s.size()) {
      if (s.at(start) == '0') {
        nums[index] = 0;
        get_ip_strings(s, start + 1, nums, result, index + 1);
      } else {
        for (int j{start}; j < s.size(); ++j) {
          int n = std::stoi(s.substr(start, j - start + 1));
          if (n < 256) {
            nums[index] = n;
            get_ip_strings(s, j+1, nums, result, index + 1);
          } else {
            break;
          }
        }
      }
    }
  }
}

std::vector<std::string> Backtracking::restoreIpAddresses(std::string s) {
  std::vector<std::string> result;
  std::vector<int> pos_vec(4, 0);
  get_ip_strings(s, 0, pos_vec, result, 0);
  return result;
}

std::vector<std::string> Backtracking::PermutationWithRepeatedCharacter(std::string S) {
  std::vector<std::string> result;
  std::function<void(std::string, std::vector<bool>, std::string, int)> permu_int;
  permu_int = [&](std::string str, std::vector<bool> visited, std::string re, int index) {
    if (index == str.length()) {
      result.push_back(re);
    } else {
      for (int i{0}; i < str.length(); ++i) {
        if (visited[i]){
          continue;
        }
        if (i > 0 && str[i] == str[i-1] && !visited[i-1]) {
          continue;
        }
        visited[i] = true;
        re += str[i];
        permu_int(str, visited, re, index + 1);
        visited[i] = false;
        re.pop_back();
      }
    }
  };
  std::sort(S.begin(), S.end());
  std::vector<bool> flags(S.size(), false);
  std::string res;
  permu_int(S, flags, res, 0);
  return result;
}