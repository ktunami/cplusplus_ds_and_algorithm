/***************************************************
* File:   thread_binary_tree.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include "thread_binary_tree.h"
#include "binary_tree.h"

TBTNode * ThreadBinaryTree::CreateBinaryTree(std::vector<int> &input) {
  return BinaryTree::CreateFromArray<TBTNode>(input);
}

void ThreadBinaryTree::InOrderThreading(TBTNode * root, TBTNode *& pre) {
  if (root) {
    InOrderThreading(root->left, pre);
    if (!root->left) {
      root->left = pre;
      root->ltag = 1;
    }
    if (pre && !pre->right) {
      pre->right = root;
      pre->rtag = 1;
    }
    pre = root;
    InOrderThreading(root->right, pre);
  }
}

std::vector<int> ThreadBinaryTree::InOrderTraversalOfTBTr(TBTNode * root) {
  std::vector<int> result;
  std::function<TBTNode * (TBTNode *)>  find_left_most;
  find_left_most = [&](TBTNode * rt) {
    while (rt && rt->ltag == 0) {
      rt = rt->left;
    }
    return rt;
  };
  auto cur{find_left_most(root)};
  while(cur) {
    result.push_back(cur->val);
    if (cur->rtag == 1) {
      cur = cur->right;
    } else {
      cur = find_left_most(cur->right);
    }
  }
  return result;
}