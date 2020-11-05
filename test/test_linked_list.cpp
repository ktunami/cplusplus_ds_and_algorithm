/***************************************************
* File:   test_linked_list.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "linked_list_int.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

TEST(TestLinkedList, CreatByTailInsert) {
  std::vector<int> input_vec{1,2,3,4,5};
  auto len{input_vec.size()};
  LinkedList ls;
  ListNode * with_head{ls.CreatByTailInsert(input_vec, true)};
  ListNode * without_head{ls.CreatByTailInsert(input_vec, false)};
  std::vector<int> with_head_vec{ls.LinkedListTraversal(with_head,true)};
  std::vector<int> without_head_vec{ls.LinkedListTraversal(without_head, false)};
  for (int i{0}; i < len; ++i) {
    ASSERT_EQ(input_vec.at(i), with_head_vec.at(i));
    ASSERT_EQ(input_vec.at(i), without_head_vec.at(i));
  }
  ls.DeleteLinkedList(with_head);
  ls.DeleteLinkedList(without_head);
}

TEST(TestLinkedList, ReverseList) {
  LinkedList ls;
  std::vector<int> input_vec{1,2,3,4,5};
  auto len{input_vec.size()};
  auto origin{ls.CreatByTailInsert(input_vec, false)};
  auto reversed{ls.ReverseList(origin)};
  std::vector<int> reversed_vec{ls.LinkedListTraversal(reversed,false)};
  for (int i{0}; i < len; ++i) {
    ASSERT_EQ(input_vec.at(i), reversed_vec.at(len-1-i));
  }
 ls.DeleteLinkedList(reversed);
}


TEST(TestLinkedList, ReverseList2) {
  LinkedList ls;
  std::vector<int> input_vec{1,2,3,4,5};
  auto len{input_vec.size()};
  auto origin{ls.CreatByTailInsert(input_vec, false)};
  auto reversed{ls.ReverseList2(origin)};
  std::vector<int> reversed_vec{ls.LinkedListTraversal(reversed,false)};
  for (int i{0}; i < len; ++i) {
    ASSERT_EQ(input_vec.at(i), reversed_vec.at(len-1-i));
  }
  ls.DeleteLinkedList(reversed);
}

TEST(TestLinkedList, CreateCycleList) {
  LinkedList ls;
  std::vector<int> input_vec{0,1,2,3,4,5,6};
  int pos{4};
  auto lst{ls.CreateCycleList(input_vec, pos)};
  ListNode * cur{lst};
  for (int i{0}; i < input_vec.size(); ++i) {
    cur = cur->next;
  }
  ASSERT_EQ(cur->val, 4);
}

TEST(TestLinkedList, hasCycle) {
  LinkedList ls;
  std::vector<int> input_vec{0,1,2,3,4,5,6};
  int pos{4};
  auto lst_with_cycle{ls.CreateCycleList(input_vec, pos)};
  auto lst_without_cycle{ls.CreatByTailInsert(input_vec, false)};
  ASSERT_TRUE(ls.hasCycle(lst_with_cycle));
  ASSERT_FALSE(ls.hasCycle(lst_without_cycle));
}

TEST(TestLinkedList, detectCycle) {
  LinkedList ls;
  std::vector<int> input_vec{0,1,2,3,4,5,6};
  int pos{4};
  auto lst_with_cycle{ls.CreateCycleList(input_vec, pos)};
  ASSERT_EQ(ls.detectCycle(lst_with_cycle)->val, pos);
}

TEST(TestLinkedList, ysf) {
  LinkedList ls;
  ASSERT_EQ(ls.ysf(5,3),3);
}

TEST(TestLinkedList, mergeTwoLists) {
  LinkedList ls;
  std::vector<int> input_vec1{1,3,5};
  std::vector<int> input_vec2{2,4,6,7,8};
  std::vector<int> expected_vec{1,2,3,4,5,6,7,8};
  ListNode * list1{ls.CreatByTailInsert(input_vec1, false)};
  ListNode * list2{ls.CreatByTailInsert(input_vec2, false)};
  ListNode * merged_list{ls.mergeTwoLists(list1,list2)};
  std::vector<int> result_vec{ls.LinkedListTraversal(merged_list, false)};
  ASSERT_EQ(result_vec.size(), expected_vec.size());
  for (int i{0}; i < result_vec.size(); ++i) {
    ASSERT_EQ(result_vec.at(i), expected_vec.at(i));
  }
}

TEST(TestLinkedList, FindFirstCommonNode) {
  LinkedList ls;
  std::vector<int> input_vec1{1,3,5};
  std::vector<int> input_vec2{2,4,6,7,8};
  ListNode * list1{ls.CreatByTailInsert(input_vec1, false)};
  ListNode * list2{ls.CreatByTailInsert(input_vec2, false)};
  ListNode * l1_idx{list1}, *l2_idx{list2};
  while(l1_idx && l1_idx->next) {
    l1_idx = l1_idx->next;
    l2_idx = l2_idx->next;
  }
  l1_idx->next = l2_idx;
  /* 1-> 3-> 5
   *         |
   * 2-> 4-> 6-> 7-> 8
   * */
  ASSERT_EQ(ls.FindFirstCommonNode(list1,list2)->val, 6);
}


std::vector<int> GetKReversedVec(std::vector<int> const& vec, int k) {
  LinkedList ls;
  ListNode * list{ls.CreatByTailInsert(vec, false)};
  ListNode * re{ls.reverseKGroup(list,k)};
  std::vector<int> result{ls.LinkedListTraversal(re, false)};
  ls.DeleteLinkedList(re);
  return result;
}

TEST(TestLinkedList, reverseKGroup) {
  std::vector<int> input_vec{1,2,3,4,5};
  int k1{1},k2{2},k3{6},k4{5};
  std::vector<int> expected_result1{1,2,3,4,5};
  std::vector<int> expected_result2{2,1,4,3,5};
  std::vector<int> expected_result3{1,2,3,4,5};
  std::vector<int> expected_result4{5,4,3,2,1};
  auto vec1{GetKReversedVec(input_vec,k1)};
  auto vec2{GetKReversedVec(input_vec,k2)};
  auto vec3{GetKReversedVec(input_vec,k3)};
  auto vec4{GetKReversedVec(input_vec,k4)};
  for (int i{0}; i < 5; i++) {
    ASSERT_EQ(expected_result1.at(i), vec1.at(i));
    ASSERT_EQ(expected_result2.at(i), vec2.at(i));
    ASSERT_EQ(expected_result3.at(i), vec3.at(i));
    ASSERT_EQ(expected_result4.at(i), vec4.at(i));
  }
}