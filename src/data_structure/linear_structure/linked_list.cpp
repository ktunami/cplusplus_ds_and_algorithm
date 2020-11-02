/***************************************************
* File:   linked_list.cpp
* Brief:  About linked list
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "data_structure/linear_structure/linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
  head = nullptr;
  tail_ptr = nullptr;
}

LinkedList::~LinkedList(){
  while (head) {
    Node * cur = head;
    free(cur);
    head = head->next;
  }
}

void LinkedList::CreateByArrayTailInsert(int arr[], int len) {
  Node * cur = (Node *)malloc(sizeof(Node));
  cur->next = nullptr;
  head = cur;
  tail_ptr = head;
  for (int i = 0; i < len; ++i) {
    Node * cur = (Node *)malloc(sizeof(Node));
    cur->data = arr[i];
    cur->next = nullptr;
    tail_ptr->next = cur;
    tail_ptr = tail_ptr->next;
  }
}

void LinkedList::PrintList() {
  Node * p = head->next;
  while (p) {
    std::cout << p->data << std::endl;
    p = p->next;
  }
}

void LinkedList::ReverseKGroup(int k) {
  Node * j = head->next;
  Node * i = head->next;
  Node * last_tail = head;
  while (j) {
    int count = k;
    while (j && count > 0) {
      j = j->next;
      --count;
    }
    if (count > 0) {
      break;
    } else {
      Node * h = nullptr;
      int num = k;
      Node * current_front = last_tail;
      while (i!=j) {
        Node * c = i;
        i = i->next;
        if (h == nullptr) {
          c->next = j;
          last_tail = c;
        } else {
          c->next = h;
        }
        h = c;
        --num;
      }
      current_front->next = h;
    }
  }
}
