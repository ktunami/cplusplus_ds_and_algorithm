/***************************************************
* File:   linked_list_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_LINKEDLIST_H_INT
#define C_PRACTICE_LINKEDLIST_H_INT

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

  ///@brief Leecode25
  void ReverseKGroup(int k);


  ///@brief Head node of the linked list
  Node * head;
  ///@brief The tail pointer of the linked list
  Node * tail_ptr;
};


#endif//C_PRACTICE_LINKEDLIST_H_INT
