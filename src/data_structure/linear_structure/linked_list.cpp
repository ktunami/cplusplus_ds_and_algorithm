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

ListNode * LinkedList::detectCycle(ListNode *head) {
  ListNode * result{nullptr};
  ListNode * meet_ptr{nullptr};
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
      meet_ptr = slow_pt;
      break;
    }
  }
  if (nullptr != meet_ptr) {
    slow_pt = head;
    while(slow_pt != meet_ptr) {
      slow_pt = slow_pt->next;
      meet_ptr = meet_ptr->next;
    }
    result = slow_pt;
  }
  return result;
}

int LinkedList::ysf(int n, int m) {
  int result{0};
  for (int i{2}; i <= n; i++) {
    result = (result + m) % i;
  }
  return result;
}

ListNode * LinkedList::mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode * merged_node{nullptr};
  if (!l1) {
    merged_node = l2;
  } else if (!l2) {
    merged_node = l1;
  } else {
    ListNode * idx1{l1}, * idx2{l2}, * idx_merge{nullptr};
    if (idx1->val < idx2->val) {
      merged_node = idx1;
      idx1 = idx1->next;
    } else {
      merged_node = idx2;
      idx2 = idx2->next;
    }
    idx_merge = merged_node;
    while (idx1 && idx2) {
      if (idx1->val < idx2->val) {
        idx_merge->next = idx1;
        idx1 = idx1->next;
      } else {
        idx_merge->next = idx2;
        idx2 = idx2->next;
      }
      idx_merge = idx_merge->next;
    }
    while (idx1) {
      idx_merge->next = idx1;
      idx1 = idx1->next;
      idx_merge = idx_merge->next;
    }
    while (idx2) {
      idx_merge->next = idx2;
      idx2 = idx2->next;
      idx_merge = idx_merge->next;
    }
  }
  return merged_node;
}