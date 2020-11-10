/***************************************************
* File:   linked_list.cpp
* Brief:  About linked list
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "linked_list.h"
#include <stack>
#include <queue>
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

ListNode* LinkedList::oddEvenList(ListNode* head) {
  ListNode * even_list{nullptr}, * pre{head}, * cur{nullptr}, *idx_even{nullptr}, *lst{head};
  while(pre && pre->next) {
    lst = pre;
    cur = pre->next;
    pre->next = cur->next;
    cur->next = nullptr; //Add this or else there will be a cycle!!
    pre = pre->next;
    if (!even_list) {
      even_list = cur;
      idx_even = cur;
    } else {
      idx_even->next = cur;
      idx_even = idx_even->next;
    }
  }
  if (pre) {
    pre->next = even_list;
  } else {
    lst->next = even_list;
  }
  return head;
}

ListNode * LinkedList::sortInList(ListNode* head) {
  std::stack<ListNode *> st;
  while(head) {
    auto cur{head};
    head = head->next;
    while (!st.empty() && cur->val < st.top()->val) {
      auto tp{st.top()};
      tp->next = head;
      head = tp;
      st.pop();
    }
    st.push(cur);
  }
  while(!st.empty()) {
    auto tp{st.top()};
    tp->next = head;
    head = tp;
    st.pop();
  }
  return head;
}

ListNode * LinkedList::GetMiddle(ListNode * start, ListNode * end) {
  ListNode * p{start}, * q{start}, *last{nullptr} ;
  while (p != end) {
    while (p != end && p->val <= start->val) {
      last = p;
      p = p->next;
    }
    if (p != end) {
      if (!q) {
        q = p->next;
      }
      while (q!= end && q->val > start->val) {
        q = q->next;
      }
      if (q!= end) {
        int tmp{p->val};
        p->val = q->val;
        q->val = tmp;
      } else {
        break;
      }
    }
  }
  if (last != start) {
    int tmp{start->val};
    start->val = last->val;
    last->val = tmp;
  }
  return last;
}

void LinkedList::SortLinkedList(ListNode * start, ListNode * end) {
  if (start != end) {
    auto middle{GetMiddle(start, end)};
    SortLinkedList(start, middle);
    SortLinkedList(middle->next, end);
  }
}

ListNode* LinkedList::sortInList2(ListNode* head) {
  SortLinkedList(head, nullptr);
  return head;
}

ListNode* LinkedList::sortInList3(ListNode* head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode * slow{head}, * fast{head->next};
  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode * head2{slow->next};
  slow->next = nullptr;
  ListNode * lst1{sortInList(head)};
  ListNode * lst2{sortInList(head2)};
  ListNode * final_node{new ListNode(100)};
  ListNode * cur{final_node};
  while (lst1 && lst2) {
    if (lst1->val < lst2->val) {
      cur->next = lst1;
      lst1 = lst1->next;
    } else {
      cur->next = lst2;
      lst2 = lst2->next;
    }
    cur = cur->next;
  }
  cur->next = lst1 ? lst1 : lst2;
  cur = final_node;
  final_node = final_node->next;
  delete cur;
  return final_node;
}

ListNode* LinkedList::addInList(ListNode* head1, ListNode* head2) {
  std::stack<ListNode *> st1, st2;
  ListNode * idx1{head1}, * idx2{head2}, * result{nullptr};
  while (idx1) {
    st1.push(idx1);
    idx1 = idx1->next;
  }
  while (idx2) {
    st2.push(idx2);
    idx2 = idx2->next;
  }
  int carry{0};
  while (!st1.empty() && !st2.empty()) {
    auto sum{st1.top()->val + st2.top()->val + carry};
    auto cur{new ListNode(sum % 10)};
    cur->next = result;
    result = cur;
    if (sum >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
    st1.pop();
    st2.pop();
  }
  while (!st1.empty()) {
    auto sum{st1.top()->val + carry};
    auto cur{new ListNode(sum % 10)};
    cur->next = result;
    result = cur;
    if (sum >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
    st1.pop();
  }
  while (!st2.empty()) {
    auto sum{st2.top()->val + carry};
    auto cur{new ListNode(sum % 10)};
    cur->next = result;
    result = cur;
    if (sum >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
    st2.pop();
  }
  if (carry == 1) {
    auto cur{new ListNode(1)};
    cur->next = result;
    result = cur;
  }
  return result;
}



ListNode *LinkedList::mergeKLists(std::vector<ListNode *> &lists) {
   ListNode * result{new ListNode(0)};
   ListNode * cur{result};
   ///@ATTENTION: std::greater<int> ==> Min heap
   ///               std::less<int> ==> Max heap
   auto cmp = [] (ListNode * p1, ListNode * p2) {
     return p1->val > p2->val;
   };
   std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> qu(cmp);
   for (int i{0}; i < lists.size(); ++i) {
     qu.push(lists.at(i));
   }
   while(!qu.empty()) {
     auto idx{qu.top()};
     qu.pop();
     cur->next = idx;
     cur = idx;
     if (idx->next) {
       qu.push(idx->next);
     }
     idx->next = nullptr;
   }
   cur = result;
   result = result->next;
   delete cur;
   return result;
}

ListNode* LinkedList::reverseBetween(ListNode* head, int m, int n) {
  ListNode * head_node{new ListNode(0)};
  head_node->next = head;
  head = head_node;
  ListNode * result{head}, * m_idx{head}, * m_pre_idx{head};
  ListNode * n_idx{head}, * n_post_idx{head};
  int count_n{0}, count_m{0};
  if (m < n && m > 0) {
    while(m_idx && count_m < m) {
      m_pre_idx = m_idx;
      m_idx = m_idx->next;
      ++count_m;
    }
    while(n_idx && count_n < n) {
      n_idx = n_idx->next;
      ++count_n;
    }
    if (m_idx && n_idx) {
      n_post_idx = n_idx->next;
      ListNode * pre{nullptr}, *cur{m_idx}, *nxt{nullptr};
      n_idx->next = nullptr;
      while (cur) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      m_pre_idx->next = pre;
      m_idx->next = n_post_idx;
    }
  }
  auto cur{head};
  head = head->next;
  result = head;
  delete cur;
  return result;
}

ListNode* LinkedList::deleteDuplicatesNodes(ListNode* head) {
  ListNode * pre{head};
  while (pre && pre->next) {
    if (pre->val == pre->next->val) {
      auto cur{pre->next};
      pre->next = cur->next;
      delete cur;
    } else {
      pre = pre->next;
    }
  }
  return head;
}

bool LinkedList::isPail(ListNode* head) {
  bool result{true};
  ListNode * cur{head};
  std::stack<ListNode *> st;
  while(cur) {
    st.push(cur);
    cur = cur->next;
  }
  cur = head;
  while(!st.empty()) {
    if (st.top()->val != cur->val) {
      result = false;
      break;
    }
    st.pop();
    cur = cur->next;
  }
  return result;
}