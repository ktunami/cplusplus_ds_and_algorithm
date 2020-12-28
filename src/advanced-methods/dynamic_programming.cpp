/***************************************************
* File:   dynamic_programming.cpp
* Brief:   Dynamic programming algprithms
* Author: kate
* Update: 2020/12/26.
***************************************************/

#include <vector>

#include "dynamic_programming.h"

int DProAlgo::FibonacciNum1(int n) {
  if (n <= 1) {
    return n;
  } else {
    std::vector<int> fib_arr{0,1};
    for(int i{2}; i <= n; ++i) {
      int len = fib_arr.size();
      fib_arr.push_back(fib_arr[len-1] + fib_arr[len-2]);
    }
    return fib_arr.back();
  }
}

int DProAlgo::FibonacciNum2(int n) {
  if (0 == n) {
    return 0;
  }
  std::function<std::pair<int, int>(int)> get_pair;
  get_pair = [&](int n) {
    if (1 == n) {
      return std::pair<int, int>(0,1);
    } else {
      int m = n >> 1;
      auto pir{get_pair(m)};
      int prev = pir.first * pir.first + pir.second * pir.second;
      int cur = pir.second * (2 * pir.first + pir.second);
      int next = prev + cur;
      if (n % 2 == 0) {
        return std::pair<int, int>(prev, cur);
      } else {
        return std::pair<int, int>(cur, next);
      }
    }
  };
  return get_pair(n).second;
}

int DProAlgo::climbStairs(int n) {
  std::vector<int> steps{0,1,2};
  for (int i{3}; i <= n; ++i) {
    steps.push_back(steps[i-1] + steps[i-2]);
  }
  return steps[n];
}

int DProAlgo::maxSubArray(std::vector<int>& nums) {
  int result{0};
  if (!nums.empty()) {
    std::vector<int> end_sum{nums[0]};
    int max_num{nums[0]};
    for(int i{1}; i < nums.size(); ++i) {
      end_sum.push_back(std::max(end_sum[i-1] + nums[i], nums[i]));
      if (max_num < end_sum.back()) {
        max_num = end_sum.back();
      }
    }
    result = max_num;
  }
  return result;
}

int DProAlgo::lengthOfLIS(std::vector<int>& nums) {
  int result{0};
  if (!nums.empty()) {
    std::vector<int> end_len{1};
    result = 1;
    for(int i{1}; i < nums.size(); ++i) {
      int cur_max = 1;
      for (int j{0}; j < i; ++j) {
        if (nums[i] > nums[j]) {
          cur_max = cur_max > (end_len[j] + 1) ? cur_max : (end_len[j] + 1);
        }
      }
      end_len.push_back(cur_max);
      result = result > end_len.back() ? result : end_len.back();
    }
  }
  return result;
}