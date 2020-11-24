/***************************************************
* File:   test_binary_tree.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/10.
***************************************************/

#include <gtest/gtest.h>

#include "binary_tree_int.h"
#include "common_test_method.h"

TEST(BinaryTree, CreateFromArray) {
  std::vector<int> input{1,2,3,4,5,0,0,0,0,6,7};
  auto biTree{BinaryTree::CreateFromArray(input)};
  std::vector<int> pre_order_traversal;
  BinaryTree::Traversal(biTree, pre_order_traversal, BinaryTree::TraversalType::PRE_ORDER);
  std::vector<int> expected_result{1,2,4,5,6,7,3};
  CheckIntVecEquality(expected_result,pre_order_traversal);
}

TEST(BinaryTree, zigzagLevelOrder) {
  std::vector<int> input{1,2,3,4,5,0,0,0,0,6,7};
  auto biTree{BinaryTree::CreateFromArray(input)};
  std::vector<std::vector<int>> expected_result{{1},{3,2},{4,5},{7,6}};
  Check2DIntVecEquality(BinaryTree::zigzagLevelOrder(biTree), expected_result);
}

TEST(BinaryTree, creat_frm_preorder_inorder) {
  std::vector<int> pre_order{1,2,4,5,6,7,3,8,9};
  std::vector<int> in_order{4,2,6,5,7,1,3,9,8};
  int to = pre_order.size()-1;
  auto tr{BinaryTree::creat_frm_preorder_inorder(pre_order,in_order,0,to,0,to)};
  std::vector<int> pre_order_traversal, in_order_traversal;
  BinaryTree::Traversal(tr, pre_order_traversal, BinaryTree::TraversalType::PRE_ORDER);
  BinaryTree::Traversal(tr, in_order_traversal, BinaryTree::TraversalType::IN_ORDER);
  CheckIntVecEquality(pre_order, pre_order_traversal);
  CheckIntVecEquality(in_order, in_order_traversal);
}
