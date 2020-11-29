/***************************************************
* File:   thread_binary_tree_int.h
* Brief:  Threaded Binary Tree
* Author: kate
* Update: 2020/11/29.
***************************************************/


#ifndef C_PRACTICE_THREAD_BINARY_TREE_INT_H
#define C_PRACTICE_THREAD_BINARY_TREE_INT_H

#include <vector>

struct TBTNode {
  int val;
  int ltag;
  int rtag;
  TBTNode * left;
  TBTNode * right;
  TBTNode(int x) : val{x}, ltag{0}, rtag{0}, left{nullptr}, right{nullptr}{}
};

class ThreadBinaryTree{
public:
  /// @brief Create a common binary tree from input vector
  TBTNode * CreateBinaryTree(std::vector<int> &input);

  /// @brief In-order Threading
  void InOrderThreading(TBTNode * root, TBTNode *& pre);

  /// @brief In-order traversal of threaded binary tree
  std::vector<int> InOrderTraversalOfTBTr(TBTNode * root);
};


#endif//C_PRACTICE_THREAD_BINARY_TREE_INT_H
