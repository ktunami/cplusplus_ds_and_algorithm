/***************************************************
* File:   test_linked_list.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include <gtest/gtest.h>
#include <functional>
#include <iostream>
#include <memory>

#include "linked_list_int.h"
#include "common_test_method.h"

TEST(TestLinkedList, CreatByTailInsert) {
  std::vector<int> input_vec{1,2,3,4,5};
  LinkedList ls;
  ListNode * with_head{ls.CreatByTailInsert(input_vec, true)};
  ListNode * without_head{ls.CreatByTailInsert(input_vec, false)};
  std::vector<int> with_head_vec{ls.LinkedListTraversal(with_head,true)};
  std::vector<int> without_head_vec{ls.LinkedListTraversal(without_head, false)};
  CheckIntVecEquality(input_vec, with_head_vec);
  CheckIntVecEquality(input_vec, without_head_vec);
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
  CheckIntVecEquality(result_vec, expected_vec);
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
  CheckIntVecEquality(expected_result1,vec1);
  CheckIntVecEquality(expected_result2,vec2);
  CheckIntVecEquality(expected_result3,vec3);
  CheckIntVecEquality(expected_result4,vec4);
}

std::vector<int> GetKReversedVecInplace(std::vector<int> const& vec, int k) {
  LinkedList ls;
  ListNode * list{ls.CreatByTailInsert(vec, false)};
  ListNode * re{ls.reverseKGroupInplace(list,k)};
  std::vector<int> result{ls.LinkedListTraversal(re, false)};
  ls.DeleteLinkedList(re);
  return result;
}


TEST(TestLinkedList, reverseKGroupInplace) {
  std::vector<int> input_vec{1,2,3,4,5};
  int k1{1},k2{2},k3{6},k4{5};
  std::vector<int> expected_result1{1,2,3,4,5};
  std::vector<int> expected_result2{2,1,4,3,5};
  std::vector<int> expected_result3{1,2,3,4,5};
  std::vector<int> expected_result4{5,4,3,2,1};
  auto vec1{GetKReversedVecInplace(input_vec,k1)};
  auto vec2{GetKReversedVecInplace(input_vec,k2)};
  auto vec3{GetKReversedVecInplace(input_vec,k3)};
  auto vec4{GetKReversedVecInplace(input_vec,k4)};
  CheckIntVecEquality(expected_result1,vec1);
  CheckIntVecEquality(expected_result2,vec2);
  CheckIntVecEquality(expected_result3,vec3);
  CheckIntVecEquality(expected_result4,vec4);
}

void CheckDeleteDuplicates(std::vector<int> &input, std::vector<int> &expected_result) {
  LinkedList ls;
  auto origin_list{ls.CreatByTailInsert(input, false)};
  auto processed_list{ls.deleteDuplicates(origin_list)};
  auto re{ls.LinkedListTraversal(processed_list, false)};
  CheckIntVecEquality(expected_result,re);
}


TEST(TestLinkedList,deleteDuplicates) {
  std::vector<int> input1{1,1,2,2,2};
  std::vector<int> input2{1,2,2,3,3};
  std::vector<int> input3{1,2,2,3,4,4};
  std::vector<int> input4{1,1,3,2};
  std::vector<int> expected_result1{};
  std::vector<int> expected_result2{1};
  std::vector<int> expected_result3{1,3};
  std::vector<int> expected_result4{3,2};
  CheckDeleteDuplicates(input1,expected_result1);
  CheckDeleteDuplicates(input2,expected_result2);
  CheckDeleteDuplicates(input3,expected_result3);
  CheckDeleteDuplicates(input4,expected_result4);
}

void CheckRemoveNthFromEnd(std::vector<int> &input, std::vector<int> &expected_result, int n) {
  LinkedList ls;
  auto list{ls.CreatByTailInsert(input,false)};
  auto re{ls.removeNthFromEnd(list, n)};
  auto vec{ls.LinkedListTraversal(re, false)};
  CheckIntVecEquality(expected_result,vec);
}

TEST(TestLinkedList,removeNthFromEnd) {
  std::vector<int> input{7,6,5,4,3,2,1};
  std::vector<int> expected_result1{7,6,5,4,3,1};
  std::vector<int> expected_result2{6,5,4,3,2,1};
  std::vector<int> expected_result3{7,6,5,4,3,2};
  std::vector<int> expected_result4{};
  int n1{2}, n2{7},n3{1},n4{8};
  CheckRemoveNthFromEnd(input,expected_result1,n1);
  CheckRemoveNthFromEnd(input,expected_result2,n2);
  CheckRemoveNthFromEnd(input,expected_result3,n3);
  CheckRemoveNthFromEnd(input,expected_result4,n4);
}

void CheckOddEvenList(std::vector<int> &input, std::vector<int> &expected_result) {
  LinkedList ls;
  auto list{ls.CreatByTailInsert(input,false)};
  auto re{ls.oddEvenList(list)};
  auto vec{ls.LinkedListTraversal(re, false)};
  CheckIntVecEquality(expected_result,vec);
}

TEST(TestLinkedList, oddEvenList) {
  std::vector<int> input1{1,2,3,4,5,6,7};
  std::vector<int> expected_result1{1,3,5,7,2,4,6};
  std::vector<int> input2{1,2,3,4,5,6};
  std::vector<int> expected_result2{1,3,5,2,4,6};
  std::vector<int> input3{1,2};
  std::vector<int> expected_result3{1,2};
  std::vector<int> input4{1};
  std::vector<int> expected_result4{1};
  CheckOddEvenList(input1,expected_result1);
  CheckOddEvenList(input2,expected_result2);
  CheckOddEvenList(input3,expected_result3);
  CheckOddEvenList(input4,expected_result4);
}

void CheckSortInList(
    std::vector<int> &input,
    std::vector<int> &expected_result,
    std::function<ListNode * (ListNode *)> sort_func) {
  LinkedList ls;
  auto origin{ls.CreatByTailInsert(input, false)};
  auto sorted{sort_func(origin)};
  auto vec{ls.LinkedListTraversal(sorted, false)};
  CheckIntVecEquality(expected_result,vec);
}

TEST(TestLinkedList, sortInList123) {
  std::vector<std::vector<int>> inputs{
    {1,3,2,5,4,0},
    {0,1,2,3,4,5},
    {5,4,3,2,1,0},
    {3,1,2,4,5,0}
  };
  std::vector<int> expected_result{0,1,2,3,4,5};
  LinkedList ls;
  auto func1{std::bind(&LinkedList::sortInList, &ls, std::placeholders::_1)};
  auto func2{std::bind(&LinkedList::sortInList2, &ls, std::placeholders::_1)};
  auto func3{std::bind(&LinkedList::sortInList3, &ls, std::placeholders::_1)};
  for (int i{0}; i < inputs.size(); ++i) {
    CheckSortInList(inputs.at(i), expected_result, func1);
    CheckSortInList(inputs.at(i), expected_result, func2);
    CheckSortInList(inputs.at(i), expected_result, func3);
  }
}

void CheckAddInList(
    std::vector<int> &input1,
    std::vector<int> &input2,
    std::vector<int> &expected_result) {
  LinkedList ls;
  auto list1{ls.CreatByTailInsert(input1, false)};
  auto list2{ls.CreatByTailInsert(input2, false)};
  auto list3{ls.addInList(list1, list2)};
  auto result{ls.LinkedListTraversal(list3, false)};
  CheckIntVecEquality(expected_result,result);
}

TEST(TestLinkedList, addInList) {
  std::vector<std::vector<int>> input1{
    {9,3,7},
    {1,1,1,1},
    {1,0,9,9}
  };
  std::vector<std::vector<int>> input2{
    {6,3},
    {2,2,2,2},
    {2,2}
  };
  std::vector<std::vector<int>> expected_result{
    {1,0,0,0},
    {3,3,3,3},
    {1,1,2,1}
  };
  for (int i{0}; i < input1.size(); ++i) {
    CheckAddInList(input1.at(i),input2.at(i),expected_result.at(i));
  }
}

void CheckMergeKLists (
    std::vector<std::vector<int>> &inputs,
    std::vector<int> &expected_result) {
  std::vector<ListNode *> lists;
  LinkedList ls;
  for (int i{0}; i < inputs.size(); ++i) {
    lists.push_back(ls.CreatByTailInsert(inputs.at(i), false));
  }
  auto result{ls.LinkedListTraversal(ls.mergeKLists(lists), false)};
  CheckIntVecEquality(expected_result,result);
}

TEST(TestLinkedList, mergeKLists){
  std::vector<std::vector<int>> inputs{
    {1,4,5}, {1,3,4}, {2,6}
  };
  std::vector<int> expected_result{1,1,2,3,4,4,5,6};
  CheckMergeKLists(inputs, expected_result);
}

TEST(TestLinkedList, reverseBetween) {
  std::vector<int> vec{3,5};
  std::vector<int> expected_result{5,3};
  int m{1},n{2};
  LinkedList ls;
  auto list{ls.CreatByTailInsert(vec,false)};
  auto result{ls.LinkedListTraversal(ls.reverseBetween(list,m,n), false)};
  CheckIntVecEquality(expected_result,result);
}

TEST(TestLinkedList, deleteDuplicatesNodes) {
  std::vector<int> vec{3,3,4,4,5};
  std::vector<int> expected_result{3,4,5};
  LinkedList ls;
  auto list{ls.CreatByTailInsert(vec,false)};
  auto result{ls.LinkedListTraversal(ls.deleteDuplicatesNodes(list), false)};
  CheckIntVecEquality(expected_result,result);
}

TEST(TestLinkedList, isPail) {
  std::vector<std::vector<int>> inputs {
    {3,4,4,3},
    {3,4,3},
    {3,4,4,3,6}
  };
  std::vector<bool> result{true, true, false};
  LinkedList ls;
  for (int i{0}; i < inputs.size(); ++i) {
    auto list{ls.CreatByTailInsert(inputs.at(i),false)};
    ASSERT_EQ(result.at(i), ls.isPail(list));
  }
}