/***************************************************
* File:   backtracking.cpp
* Brief:
* Author: kate
* Update: 2020/12/17.
***************************************************/

#include "backtracking.h"

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

std::vector<std::string> Backtracking::PermutationWithRepeatedCharacters(std::string S) {
  std::sort(S.begin(), S.end());
  std::vector<std::string> result;
  std::function<void(std::string, std::vector<bool>)> get_char_sequence;
  get_char_sequence = [&](std::string str, std::vector<bool> visited) {
    if (str.length() == S.length()) {
      result.push_back(str);
    } else {
      for (int i{0}; i < S.size(); ++i) {
        if (visited[i]) {
          continue;
        }
        if (i > 0 && S[i] == S[i-1] && !visited[i-1]) {
          continue;
        }
        str += S[i];
        visited[i] = true;
        get_char_sequence(str, visited);
        str.pop_back();
        visited[i] = false;
      }
    }
  };
  std::string tmp;
  std::vector<bool> vit(S.size(), false);
  get_char_sequence(tmp, vit);
  return result;
}

std::vector<std::string> Backtracking::PermutationWithUniqueCharacters(std::string S) {
  std::vector<std::string> result;
  std::function<void(std::string, std::vector<bool>)> get_sequence;
  get_sequence = [&](std::string str, std::vector<bool> visited) {
    if (str.length() == S.length()) {
      result.push_back(str);
    } else {
      for (int i{0}; i < S.length(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          str += S[i];
          get_sequence(str, visited);
          str.pop_back();
          visited[i] = false;
        }
      }
    }
  };
  std::string st;
  std::vector<bool> vit(S.length(), false);
  get_sequence(st, vit);
  return result;
}

std::vector<std::string> Backtracking::PermutationWithUniqueCharacters2(std::string S) {
  std::vector<std::string> result;
  auto swap = [](std::string &s, int i, int j) {
    char tmp{s[i]};
    s[i] = s[j];
    s[j] = tmp;
  };
  std::function<void(std::string, int)> get_permutation;
  get_permutation = [&](std::string str, int k) {
    if (k == str.length()) {
      result.push_back(str);
    } else {
      for (int i{k}; i < str.length(); ++i) {
        swap(str, k, i);
        get_permutation(str, k+1);
        swap(str, k, i);
      }
    }
  };
  get_permutation(S, 0);
  return result;
}

std::vector<std::vector<int> > Backtracking::combinationSum1(std::vector<int> &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int> > result;
  std::function<void(std::vector<int>, int, int, std::vector<bool>)> get_combiation;
  get_combiation = [&](std::vector<int> vec, int k, int sum, std::vector<bool> visited) {
    if (sum <= 0) {
      if (0 == sum && !vec.empty()) {
        result.push_back(vec);
      }
    } else {
      if (k < candidates.size()) {
        get_combiation(vec, k + 1, sum, visited);
        if (!(k > 0 && candidates[k] == candidates[k-1] && !visited[k-1])) {
          vec.push_back(candidates[k]);
          visited[k] = true;
          get_combiation(vec, k + 1, sum - candidates[k], visited);
        }
      }
    }
  };
  std::vector<int> tmp;
  std::vector<bool> vit(candidates.size(), false);
  get_combiation(tmp, 0, target, vit);
  return result;
}

std::vector<std::vector<int> > Backtracking::combinationSum2(std::vector<int> &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::pair<int, int>> freq;
  for (auto num : candidates) {
    if (freq.empty() || freq.back().first != num) {
      freq.emplace_back(std::pair<int, int>(num, 1));
    } else {
      ++freq.back().second;
    }
  }
  std::vector<std::vector<int> > result;
  std::vector<int> comb;
  std::function<void(int, int)> get_combinations;
  get_combinations = [&] (int pos, int rest_sum) {
    if (rest_sum == 0 && !comb.empty()) {
      result.push_back(comb);
      return;
    }
    if (pos == freq.size() || rest_sum < freq[pos].first) {
      return;
    }
    get_combinations(pos + 1, rest_sum);
    int max_size = std::min(rest_sum / freq[pos].first, freq[pos].second);
    for (int i{1}; i <= max_size; ++i) {
      comb.push_back(freq[pos].first);
      get_combinations(pos + 1, rest_sum - i * freq[pos].first);
    }
    for (int i{1}; i <= max_size; ++i) {
      comb.pop_back();
    }
  };
  get_combinations(0, target);
  return result;
}

std::vector<std::vector<std::string>> Backtracking::solveNQueens(int n) {
  std::vector<std::vector<int>> tmp_result;
  std::vector<std::vector<std::string>> result;
  std::function<void(std::vector<int>, int)> get_arrays;
  get_arrays = [&](std::vector<int> vec, int step) {
    if (n == step) {
      tmp_result.push_back(vec);
    } else {
      for (int i{0}; i < n; ++i) {
        bool ok{true};
        for (int j{0}; j < step; ++j) {
          if (vec[j] == i || (i-vec[j]) == (step-j) || (i-vec[j]) == (j-step)) {
            ok = false;
            break;
          }
        }
        if (ok) {
          vec.push_back(i);
          get_arrays(vec, step + 1);
          vec.pop_back();
        }
      }
    }
  };
  std::vector<int> road;
  get_arrays(road, 0);
  for (auto const& vec : tmp_result) {
    std::vector<std::string> re;
    for (auto num : vec) {
      std::string str(n, '.');
      str[num] = 'Q';
      re.push_back(str);
    }
    result.push_back(re);
  }
  return result;
}