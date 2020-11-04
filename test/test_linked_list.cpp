/***************************************************
* File:   test_linked_list.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "linked_list_int.h"
#include <gtest/gtest.h>
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
}

