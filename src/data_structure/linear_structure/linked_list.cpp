/***************************************************
* File:   linked_list.cpp
* Brief:  About linked list
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "data_structure/linear_structure/linked_list.h"
#include <iostream>

void LinkedList::DeleteLinkedList(ListNode * root) {
  ListNode * cur{nullptr};
  while (root != nullptr) {
    cur = root;
    root = root->next;
    delete cur;
  }
}

ListNode * LinkedList::CreatByTailInsert(std::vector<int> const& vec, bool with_head, int head_val) {
  ListNode * root{nullptr}, * it{nullptr};
  auto len{vec.size()};
  if (with_head) {
    root = new ListNode(head_val);
    it = root;
  }
  for (int i{0}; i < len; ++i) {
    ListNode * cur = new ListNode(vec.at(i));
    if (i == 0 && !with_head) {
      root = cur;
      it = cur;
      continue;
    }
    it->next = cur;
    it = cur;
  }
  return root;
}

std::vector<int> LinkedList::LinkedListTraversal(ListNode * const root, bool with_head) {
  ListNode * cur = root;
  std::vector<int> result;
  if (with_head) {
    cur = cur->next;
  }
  while (cur != nullptr) {
    result.push_back(cur->val);
    cur = cur->next;
  }
  return result;
}


ListNode* LinkedList::ReverseList(ListNode * pHead) {
  ListNode * new_head{new ListNode(404)};
  ListNode * cur = pHead;
  while(nullptr != cur) {
    auto id{cur};
    cur = cur->next;
    id->next = new_head->next;
    new_head->next = id;
  }
  cur = new_head;
  new_head = new_head->next;
  delete cur;
  return new_head;
}

ListNode * LinkedList::ReverseList2(ListNode* pHead) {
  ListNode * pre{nullptr};
  ListNode * cur{pHead};
  ListNode * next{nullptr};
  while (nullptr != cur) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}