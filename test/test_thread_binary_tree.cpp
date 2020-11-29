/***************************************************
* File:   test_thread_binary_tree.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include <gtest/gtest.h>

#include "thread_binary_tree_int.h"
#include "binary_tree.h"
#include "common_test_method.h"

TEST(ThreadBinaryTree, CreateBinaryTree) {
  ThreadBinaryTree tbtr;
  std::vector<int> input{1,2,3,4,5,0,0,0,0,6,7};
  /*             1
   *         2       3
   *       4   5
   *          6  7
   */
  std::vector<int> pre_order_expect{1,2,4,5,6,7,3};
  std::vector<int> pre_order_result;
  std::vector<int> in_order_expect{4,2,6,5,7,1,3};
  std::vector<int> in_order_result;
  std::vector<int> post_order_expect{4,6,7,5,2,3,1};
  std::vector<int> post_order_result;
  auto tr{tbtr.CreateBinaryTree(input)};
  BinaryTree::Traversal<TBTNode>(tr,pre_order_result, BinaryTree::TraversalType::PRE_ORDER);
  CheckIntVecEquality(pre_order_expect, pre_order_result);
  BinaryTree::Traversal<TBTNode>(tr,in_order_result, BinaryTree::TraversalType::IN_ORDER);
  CheckIntVecEquality(in_order_expect, in_order_result);
  BinaryTree::Traversal<TBTNode>(tr,post_order_result, BinaryTree::TraversalType::POST_ORDER);
  CheckIntVecEquality(post_order_expect, post_order_result);
  TBTNode * in{nullptr};
  tbtr.InOrderThreading(tr, in);
  auto in_order_result2{tbtr.InOrderTraversalOfTBTr(tr)};
  CheckIntVecEquality(in_order_expect, in_order_result2);
}