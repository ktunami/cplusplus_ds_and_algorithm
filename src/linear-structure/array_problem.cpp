/***************************************************
* File:   array_problem.cpp
* Brief:  Array problems
* Author: kate
* Update: 2020/11/13.
***************************************************/

#include "array_problem.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <set>

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

double ArrayProblem::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
  }
  int len1 = nums1.size(), len2 = nums2.size();
  int left = 0;
  int right = nums1.size();
  int left_max, right_min;
  int k = (len1 + len2 + 1) / 2;
  while (left <= right) {
    int i = (left + right) / 2;
    int j = k - i;
    int arr1_left = (i == 0) ? INT_MIN : nums1.at(i - 1);
    int arr1_right = (i == len1) ? INT_MAX : nums1.at(i);
    int arr2_left = (j == 0) ? INT_MIN : nums2.at(j - 1);
    int arr2_right = (j == len2) ? INT_MAX : nums2.at(j);
    left_max = std::max(arr1_left, arr2_left);
    right_min = std::min(arr1_right, arr2_right);
    if (left_max < right_min) {
       break;
    } else if (arr2_left >= arr1_right){
       left = i + 1;
    } else {
      right = i - 1;
    }
  }
  return ((len1 + len2) % 2 == 1) ? left_max : (left_max + right_min) / 2.0;
}

int ArrayProblem::minNumberdisappered(std::vector<int>& arr) {
  int len = arr.size();
  for (int i{0}; i < len; ++i) {
    if (arr.at(i) > 0 && arr.at(i) < len && arr.at(arr.at(i) - 1) != arr.at(i)) {
      std::swap(arr.at(arr.at(i - 1)), arr.at(i));
    }
  }
  for (int i{0}; i < len; ++i) {
    if (arr.at(i) != i + 1) {
      return i + 1;
    }
  }
  return len + 1;
}

std::vector<Interval> ArrayProblem::MergeIntevals(std::vector<Interval> &intervals) {
  std::sort(intervals.begin(), intervals.end(),[](Interval &ob1, Interval &ob2){
    return ob1.start < ob2.start;
  });
  std::vector<Interval> result;
  for (int i{0}; i < intervals.size(); ++i) {
    auto cur{intervals.at(i)};
    if (result.size() == 0) {
      result.push_back(cur);
    } else {
      Interval & last_one{result.back()};
      if (cur.start <= last_one.end) {
        last_one.end = (cur.end > last_one.end) ? cur.end : last_one.end;
      } else {
        result.push_back(cur);
      }
    }
  }
  return result;
}

std::vector<std::vector<int> > ArrayProblem::rotateMatrix(std::vector<std::vector<int> > mat, int n) {
  std::vector<std::vector<int> > result(n,std::vector<int>(n,0));
  for (int row{0}; row < n; ++row) {
    for (int col{0}; col < n; ++col) {
      result.at(row).at(col) = mat.at(n - col - 1).at(row);
    }
  }
  return result;
}

int ArrayProblem::MLS(std::vector<int>& arr) {
  std::set<int> hs;
  int result = 1;
  for (auto num : arr) {
    hs.insert(num);
  }
  for (auto num : arr) {
    if (!hs.count(num-1)) {
      int count = 1;
      int cur = num;
      while (hs.count(cur+1)) {
        ++count;
        cur = cur + 1;
      }
      result = count > result ? count : result;
    }
  }
  return result;
}

int ArrayProblem::InversePairs(std::vector<int> &data) {
  int result{0};
  for(int i{1}; i < data.size(); ++i) {
    int tmp{data.at(i)};
    int k = i - 1;
    while (k >= 0 && data.at(k) > tmp) {
      data[k+1] = data[k];
      --k;
      ++result;
    }
    data[k+1] = tmp;
  }
  return result;
}

int ArrayProblem::InversePairs2(std::vector<int> &data) {
  int result{0};
  std::vector<int> sorted_vec(data.size(),0);
  std::function<void(std::vector<int> &arr, int from, int to)> merge_sort;
  merge_sort = [&](std::vector<int> &arr, int from, int to){
    if (from < to) {
      auto mid{(from + to) >> 2};
      merge_sort(arr, from, mid);
      merge_sort(arr,mid + 1, to);
      int i{mid}, j{to};
      while (i >= from && j >= mid + 1) {

      }

    }
  };
}