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

///@brief Check if the linked list has cycle (Nowcoder 4)
///@param head : Root of linked list
///@return If has ring, return true

bool hasCycle(ListNode *head);

ListNode * LinkedList::CreateCycleList(std::vector<int> const& vec, int pos) {
  ListNode * result{nullptr};
  if (pos < vec.size() && pos >= 0) {
    result = CreatByTailInsert(vec, false);
    ///Attention: Result is already defined, if write "auto result{...};" here
    ///the compiler wont tell you it's a redefinition, because this is in "if block", which
    ///would be considered as another variable different from "result" in line 89
    ListNode * entry{result}, * last_ele{nullptr};
    for (int i{0}; i < pos; ++i) {
      entry = entry->next;
    }
    last_ele = entry;
    auto remain_len{vec.size() - pos - 1};
    for (int j{0}; j < remain_len; ++j) {
      last_ele = last_ele->next;
    }
    last_ele->next = entry;
  }
  return result;
}

bool LinkedList::hasCycle(ListNode * head) {
  bool result{false};
  ListNode * slow_pt{head};
  ListNode * fast_pt{head};
  while (nullptr != slow_pt && nullptr != fast_pt) {
    slow_pt = slow_pt->next;
    fast_pt = fast_pt->next;
    if (nullptr == fast_pt || nullptr == slow_pt) {
      break;
    }
    fast_pt = fast_pt->next;
    if (nullptr == fast_pt) {
      break;
    }
    if (slow_pt == fast_pt) {
      result = true;
      break;
    }
  }
  return result;
}