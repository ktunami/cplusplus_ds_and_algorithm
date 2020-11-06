/***************************************************
* File:   linked_list.cpp
* Brief:  About linked list
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "data_structure/linear_structure/linked_list.h"
#include <stack>
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

ListNode * LinkedList::FindFirstCommonNode(ListNode * pHead1, ListNode* pHead2) {
  std::stack<ListNode *> st1, st2;
  ListNode * h1{pHead1}, * h2{pHead2}, *pre{nullptr};
  if (pHead1) {
    while (h1) {
      st1.push(h1);
      h1 = h1->next;
    }
    while (h2) {
      st2.push(h2);
      h2 = h2->next;
    }
    while (!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
      pre = st1.top();
      st1.pop();
      st2.pop();
      if(!st1.empty() && !st2.empty() && st1.top() != st2.top()) {
        break;
      }
    }
  }
  return pre;
}

ListNode * LinkedList::reverseKGroup(ListNode * head, int k) {
  ListNode *next_begin{head}, * result{nullptr}, * result_idx{head};
  std::stack<ListNode *> st;
  while (next_begin) {
    int count{0};
    while (next_begin && count < k) {
      st.push(next_begin);
      next_begin = next_begin->next;
      ++count;
    }
    if (k == count) {
      if(result == nullptr) {
        result = st.top();
        result_idx = result;
        st.pop();
      }
      while(!st.empty()) {
        result_idx->next = st.top();
        result_idx = result_idx->next;
        st.pop();
      }
      result_idx->next = next_begin;
    }
  }
  if (result == nullptr) {
    result = head;
  }
  return result;
}

ListNode * LinkedList::reverseKGroupInplace(ListNode * head, int k) {
  ListNode * result{nullptr}, * next_begin{head}, * this_begin{head};
  ListNode * last_end{nullptr};
  while (next_begin) {
    int count{0};
    while(next_begin && count < k) {
      next_begin = next_begin->next;
      ++count;
    }
    if (count == k) {
      ListNode *cur{this_begin}, *pre{nullptr}, *next{nullptr};
      for(int i{0}; i < k; ++i) { //reverse k nodes
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      this_begin->next = next_begin; //this_begin is in the tail
      if (!result) {
        result = pre;
      } else {
        last_end->next = pre;
      }
      last_end = this_begin;
      this_begin = next_begin;
    } else {
      break;
    }
  }
  if(!result) {
    result = head;
  }
  return result;
}

ListNode* LinkedList::deleteDuplicates(ListNode* head) {
  ListNode * begin{head}, * cur{nullptr}, * last{nullptr};
  std::stack<ListNode *> st;
  while(begin && begin->next) {
    cur = begin->next;
    if (cur->val != begin->val) {
      last = begin;
      begin = begin->next;
    } else {
      st.push(begin);
      while(cur && cur->val == begin->val) {
        st.push(cur);
        cur = cur->next;
      }
      if (head == begin) {
        head = cur;
      } else {
        last->next = cur;
      }
      begin = cur;
    }
  }
  while (!st.empty()) {
    auto ptr{st.top()};
    st.pop();
    delete ptr;
  }
  return head;
}

ListNode* LinkedList::removeNthFromEnd(ListNode* head, int n) {
  ListNode * result{nullptr};
  std::stack<ListNode *> st;
  ListNode * cur{head};
  int count{0};
  while (cur) {
    st.push(cur);
    ++count;
    cur = cur->next;
  }
  if (count == n) {
    ListNode * cur{head};
    head = head->next;
    result = head;
    delete cur;
  } else if (count > n) {
    result = head;
    int k = 0;
    ListNode * to_be_del{nullptr}, *pre{nullptr};
    while (k < n) {
      ++k;
      to_be_del = st.top();
      st.pop();
    }
    pre = st.top();
    pre ->next = to_be_del->next;
    delete to_be_del;
  }
  return result;
}