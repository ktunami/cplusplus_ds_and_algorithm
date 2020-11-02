/***************************************************
* File:   linked_list.h
* Brief:  About linked list
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_LINKED_LIST_H
#define C_PRACTICE_LINKED_LIST_H

class LinkedList {
public:
  struct Node {
    int data = 0;
    struct Node * next = nullptr;
  };

  LinkedList();
  ~LinkedList();

  ///@brief Create a linked list from an array by "tail insert" method
  ///@param arr Array of integers
  ///@param len Length of array
  void CreateByArrayTailInsert(int arr[], int len);

  ///@brief Print the whole array
  void PrintList();

  ///@brief Reverse linked list for every k nodes, dont reverse if less than k nodes (leetcode25)
  void ReverseKGroup(int k);

private:
  ///@brief Head node of the linked list
  Node * head;
  ///@brief The tail pointer of the linked list
  Node * tail_ptr;
};


#endif//C_PRACTICE_LINKED_LIST_H
