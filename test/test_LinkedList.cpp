/*********************************************************************************
  *FileName:  test_LinkedList.cpp
  *Author:    Kate
  *Version:   1.0
  *Date:      2020/9/25
  *
**********************************************************************************/

#include "LinkedList_int.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TestLinkList, CreateByArrayTailInsert) {
  std::shared_ptr<LinkedList> lst_ptr{std::make_shared<LinkedList>()};
  int n = 9;
  int arr[9]{1,4,6,9,3,8,7,2,10};
  lst_ptr->CreateByArrayTailInsert(arr, n);
  auto cur{lst_ptr->head};
  ASSERT_FALSE(nullptr == cur->next);
  cur = cur->next;
  for (int i{0}; i<n; ++i) {
    ASSERT_FALSE(nullptr == cur);
    ASSERT_EQ(arr[i],cur->data);
    cur = cur->next;
  }
}

TEST(TestLinkList, Leecode25) {
  std::shared_ptr<LinkedList> lst_ptr_k3{std::make_shared<LinkedList>()};
  std::shared_ptr<LinkedList> lst_ptr_k1{std::make_shared<LinkedList>()};
  int arr[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  int n = 14;

  int arr1[]{3,2,1,6,5,4,9,8,7,12,11,10,13,14}; //k = 3
  lst_ptr_k3->CreateByArrayTailInsert(arr, n);
  lst_ptr_k3->Leecode25(3);
  auto cur1{lst_ptr_k1->head->next};
  for (int i{0}; i<n; ++i) {
    ASSERT_FALSE(nullptr == cur1);
    ASSERT_EQ(arr1[i],cur1->data);
    cur1 = cur1->next;
  }

  int arr2[]{14,13,12,11,10,9,8,7,6,5,4,3,2,1};  //k = 1
  lst_ptr_k1->CreateByArrayTailInsert(arr, n);
  lst_ptr_k1->Leecode25(1);
  auto cur2{lst_ptr_k1->head->next};
  for (int i{0}; i<n; ++i) {
    ASSERT_FALSE(nullptr == cur2);
    ASSERT_EQ(arr2[i],cur2->data);
    cur2 = cur2->next;
  }
}