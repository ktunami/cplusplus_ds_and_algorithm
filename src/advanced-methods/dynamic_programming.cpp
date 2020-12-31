/***************************************************
* File:   dynamic_programming.cpp
* Brief:   Dynamic programming algprithms
* Author: kate
* Update: 2020/12/26.
***************************************************/

#include <vector>
#include <iostream>

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


void PrintIntVector(std::vector<int> const & vec) {
  static int j = 1;
  std::cout << "group : " << j << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << "--";
  }
  std::cout << std::endl;
  ++j;
}

void Print2DVector(std::vector<std::vector<int>> const& vec) {
  std::cout << "Begin to print the 2D vector is: " << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    PrintIntVector(vec.at(i));
  }
  std::cout << "2D vector print over " << std::endl;
}

int DProAlgo::minimumTotal(std::vector<std::vector<int>>& triangle) {
  int result = 0;
  if (!triangle.empty()) {
    std::vector<std::vector<int>> path_weights;
    path_weights.emplace_back(std::vector<int>{triangle.at(0).at(0)});
    result = triangle.at(0).at(0);
    for (int i{1}; i < triangle.size(); ++i) {
      path_weights.emplace_back(std::vector<int>(triangle.at(i).size(), 0));
      int min_weight = INT_MAX;
      for (int j{0}; j < triangle.at(i).size(); ++j) {
        if (0 == j) {
          path_weights[i][j] = path_weights[i-1][j] + triangle[i][j];
        } else if (triangle.at(i).size() - 1 == j) {
          path_weights[i][j] = path_weights[i-1][j-1] + triangle[i][j];
        } else {
          path_weights[i][j] = std::min(path_weights[i-1][j], path_weights[i-1][j-1]) + triangle[i][j];
        }
        if (triangle.size()-1 == i) {
          min_weight = min_weight < path_weights[i][j] ? min_weight : path_weights[i][j];
        }
      }
      result = min_weight;
    }
  }
  return result;
}