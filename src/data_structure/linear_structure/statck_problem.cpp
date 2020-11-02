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