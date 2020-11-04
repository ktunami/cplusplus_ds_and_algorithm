/***************************************************
* File:   queue_problem.cpp
* Brief:  Queue problems
* Author: kate
* Update: 2020/11/3.
***************************************************/

#include "data_structure/linear_structure/queue_problem.h"
#include <deque>
#include <iostream>

std::vector<int> QueueProblem::maxSlidingWindow(std::vector<int>& nums, int k) {
  std::vector<int> result;
  std::deque<int> qu;
  for (int i{0}; i < nums.size(); ++i) {
    while (!qu.empty()) {
      if (nums.at(qu.back()) <= nums.at(i)) {
        qu.pop_back();
      } else {
        break;
      }
    }
    qu.push_back(i);
    if ((i - k) >= -1) {
      while ((i - qu.front()) >= k) {
        qu.pop_front();
      }
      if (!qu.empty()) {
        result.push_back(nums.at(qu.front()));
      } else {
        std::cout << "You are not supposed to meet here" << std::endl;
      }
    }
  }
  return result;
}

int QueueProblem::getNum(std::vector<int> &vec, int num) {
  int result{0};
  auto len{vec.size()};
  std::deque<int> largest_ele, smallest_ele;
  int l{0}, r{0};
  while (l < len) {
    while (r < len) {
      while(!largest_ele.empty() && vec.at(r) >= vec.at(largest_ele.back())) {
        largest_ele.pop_back();
      }
      largest_ele.push_back(r);
      while(!smallest_ele.empty() && vec.at(r) <= vec.at(smallest_ele.back())) {
        smallest_ele.pop_back();
      }
      smallest_ele.push_back(r);
      if ((vec.at(largest_ele.front()) - vec.at(smallest_ele.front())) > num) {
        break;
      }
      ++r;
    }
    if (largest_ele.front() == l) {
      largest_ele.pop_front();
    }
    if (smallest_ele.front() == l) {
      smallest_ele.pop_front();
    }
    result += r-l;
    ++l;
  }
  return result;
}
