/***************************************************
* File:   stack_problem.cpp
* Brief:  Solutions by applying stack
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "data_structure/linear_structure/statck_problem.h"

BTNode* StackProblem::constructMaximumBinaryTree(std::vector<int>& nums) {
  std::stack<std::pair<BTNode *, BTNode *>> son_father_ptrs;
  for (int i = 0; i < nums.size(); ++i) {
    BTNode * cur = new BTNode(nums.at(i));
    auto cur_pair{std::pair<BTNode *, BTNode *>(cur, nullptr)};
    if (0 == i) {
      son_father_ptrs.push(cur_pair);
      continue;
    }
    while(!son_father_ptrs.empty()) {
      if (cur->val < son_father_ptrs.top().first->val) {
        cur_pair.second = son_father_ptrs.top().first;
        son_father_ptrs.top().first->right = cur;
        son_father_ptrs.push(cur_pair);
        break;
      } else {
        if (nullptr == son_father_ptrs.top().second || cur->val < son_father_ptrs.top().second->val) {
          son_father_ptrs.top().second = cur;
          cur->left = son_father_ptrs.top().first;
        }
        son_father_ptrs.pop();
      }
    }
    son_father_ptrs.push(cur_pair);
  }
  BTNode * RT = nullptr;
  while (!son_father_ptrs.empty()) {
    if (son_father_ptrs.top().second == nullptr) {
      RT = son_father_ptrs.top().first;
      break;
    } else {
      son_father_ptrs.pop();
    }
  }
  return RT;
}

std::vector<int> StackProblem::dailyTemperatures(std::vector<int>& T) {
  std::vector<int> result(T.size(),0);
  std::stack<int> st;
  for (int i{0}; i < T.size(); ++i) {
    while (!st.empty() && T.at(st.top()) < T.at(i)) {
      result[st.top()] = i - st.top();
      st.pop();
    }
    st.push(i);
  }
  return result;
}

int StackProblem::largestRectangleArea(std::vector<int>& heights) {
  auto len{heights.size()};
  std::vector<int> right_idx(len,heights.size());
  std::vector<int> left_idx(len,-1);
  std::stack<int> st_r, st_l;
  for (int i{0}; i < len; ++i) {
    while (!st_r.empty() && heights.at(st_r.top()) > heights.at(i)) {
      right_idx[st_r.top()] = i;
      st_r.pop();
    }
    st_r.push(i);
    while (!st_l.empty() && heights.at(st_l.top()) > heights.at(len-i-1)) {
      left_idx[st_l.top()] = len-i-1;
      st_l.pop();
    }
    st_l.push(len-i-1);
  }
  int max_num = 0;
  for (int i{0}; i < len; ++i) {
    int cur_area = (right_idx.at(i) - left_idx.at(i) - 1) * heights.at(i);
    max_num = cur_area > max_num ? cur_area : max_num;
  }
  return max_num;
}

int StackProblem::maximalRectangle(std::vector<std::vector<char>>& matrix) {
  int result{0};
  auto len{matrix.size()};
  if (len != 0) {
    auto width{matrix.at(0).size()};
    std::vector<int> heights(width,0);
    for (int i{0}; i < len; ++i) {
      for (int j{0}; j < width; ++j) {
        if (matrix.at(i).at(j) == '1') {
          heights.at(j) += 1;
        } else {
          heights.at(j) = 0;
        }
      }
      auto cur_max{largestRectangleArea(heights)};
      result = cur_max > result ? cur_max : result;
    }
  }
  return result;
}