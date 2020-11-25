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

TEST(BinaryTree, GetRightSightView) {
  std::vector<int> pre_order{1,2,4,5,6,7,3,8,9};
  std::vector<int> in_order{4,2,6,5,7,1,3,9,8};
  std::vector<int> expected_result{1,3,8,9};
  auto result{BinaryTree::GetRightSightView(pre_order, in_order)};
  CheckIntVecEquality(result, expected_result);
}

TEST(BinaryTree, maxPathSum) {
  std::vector<int> input{-10,9,20,0,0,15,7};
  auto biTree{BinaryTree::CreateFromArray(input)};
  ASSERT_EQ(42,BinaryTree::maxPathSum(biTree));
}

TEST(BinaryTree, sumNumbers) {
  std::vector<int> input{1,9,2,3,5};
  auto biTree1{BinaryTree::CreateFromArray(input)};
  auto biTree2{BinaryTree::CreateFromArray(input)};
  ASSERT_EQ(193 + 195 + 12,BinaryTree::sumNumbers(biTree1));
  ASSERT_EQ(193 + 195 + 12,BinaryTree::sumNumbers2(biTree2));
}

