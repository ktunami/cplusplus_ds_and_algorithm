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