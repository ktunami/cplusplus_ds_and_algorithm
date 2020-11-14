/***************************************************
* File:   array_problem.cpp
* Brief:  Array problems
* Author: kate
* Update: 2020/11/13.
***************************************************/

#include "array_problem.h"
#include <queue>
#include <unordered_map>

std::vector<int> ArrayProblem::GetLeastNumbers_Solution(std::vector<int> input, int k) {
  std::priority_queue<int,std::vector<int>,std::greater<int>> qu;
  std::vector<int> result;
  if (k <= input.size()) {
    for (int i{0}; i < input.size(); ++i) {
      qu.push(input.at(i));
    }
    for (int i{0}; i < k ; ++i) {
      result.push_back(qu.top());
      qu.pop();
    }
  }
  return result;
}

void ArrayProblem::merge(int A[], int m, int B[], int n) {
  int result_idx{m + n -1}, a_idx{m - 1}, b_idx{n - 1};
  while (a_idx >= 0 && b_idx >= 0) {
    if (A[a_idx] > B[b_idx]) {
      A[result_idx--] = A[a_idx--];
    } else {
      A[result_idx--] = B[b_idx--];
    }
  }
  while (b_idx >= 0) {
    A[result_idx--] = B[b_idx--];
  }
}

std::vector<int> ArrayProblem::twoSum(std::vector<int>& numbers, int target) {
  std::vector<std::pair<int, int>> number_with_index;
  for (int i{0}; i < numbers.size(); ++i) {
    number_with_index.push_back(std::pair<int,int>(numbers.at(i), 1 + i));
  }
  std::sort(number_with_index.begin(), number_with_index.end(),
[](std::pair<int, int> &p1, std::pair<int, int>&p2){
    return p1.first < p2.first;
  });
  std::vector<int> result;
  int i = 0, j = numbers.size() - 1;
  while (i < j) {
    if (number_with_index.at(i).first + number_with_index.at(j).first == target) {
      break;
    } else if (number_with_index.at(i).first + number_with_index.at(j).first > target) {
      --j;
    } else {
      ++i;
    }
  }
  if (i < j) {
    auto a{number_with_index.at(i).second};
    auto b{number_with_index.at(j).second};
    if (a < b) {
      result.push_back(a);
      result.push_back(b);
    } else {
      result.push_back(b);
      result.push_back(a);
    }
  }
  return result;
}

std::vector<int> ArrayProblem::twoSum1(std::vector<int>& numbers, int target) {
  std::unordered_map<int,int> mp;
  std::vector<int> result;
  for (int i{0}; i < numbers.size(); ++i) {
    if (mp.find(target - numbers.at(i)) != mp.end()) {
      result.push_back(mp.at(target - numbers.at(i)));
      result.push_back(i + 1);
      break;
    }
    mp[numbers.at(i)] = i + 1;
  }
  return result;
}

std::vector<int> ArrayProblem::spiralOrder(std::vector<std::vector<int> > &matrix) {
  std::vector<int> result;
  int row = matrix.size();
  if (row > 0) {
    int col = matrix.at(0).size();
    int r_count{0}, c_count{0};
    for(int a{0}; a < row; ++a) {
      for (int j{a}; j < col-a; ++j ) {
        result.push_back(matrix.at(a).at(j));
      }
      ++r_count;
      if (r_count == row) {
        break;
      }
      for (int i{a+1}; i < row-a; ++i) {
        result.push_back(matrix.at(i).at(col-a-1));
      }
      ++c_count;
      if (c_count == col) {
        break;
      }
      for (int j{col - a - 2}; j >= a; --j) {
        result.push_back(matrix.at(row-a-1).at(j));
      }
      ++r_count;
      if (r_count == row) {
        break;
      }
      for (int i{row-a-2}; i >= a+1; --i) {
        result.push_back(matrix.at(i).at(a));
      }
      ++c_count;
      if (c_count == col) {
        break;
      }
    }
  }
  return result;
}

std::vector<std::vector<int> > ArrayProblem::threeSum(std::vector<int> &num) {
  std::vector<std::vector<int>> result;
  int len = num.size();
  if (len > 2) {
    std::sort(num.begin(),num.end());
    for (int i{0}; i < len - 2; ++i) {
      if (num.at(i) > 0) {
        continue;
      }
      int j{i + 1}, k{len - 1};
      while (j < k) {
        if (num.at(j) + num.at(k) == -num.at(i)) {
          result.push_back({num.at(i),num.at(j),num.at(k)});
          auto j_num{num.at(j)};
          while (j < k && num.at(j) == j_num) {
            ++j;
          }
          auto k_num{num.at(k)};
          while (j < k && num.at(k) == k_num) {
            --k;
          }
        } else if (num.at(j) + num.at(k) < -num.at(i)) {
          ++j;
        } else {
          --k;
        }
      }
      while (i < len - 2 && num.at(i) == num.at(i + 1)) {
        ++i;
      }
    }
  }
  return result;
}










