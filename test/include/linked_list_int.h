/***************************************************
* File:   linked_list_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_LINKEDLIST_H_INT
#define C_PRACTICE_LINKEDLIST_H_INT

#include <vector>

struct ListNode {
  int val;
  struct ListNode * next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
  ///@brief Delete a linked list
  void DeleteLinkedList(ListNode * root);

  ///@brief Traversal of Linked list
  ///@param root : Root of linked list
  ///@param with_head : If true, should jump the head node
  ///@return Traversal result
  std::vector<int> LinkedListTraversal(ListNode  * const root, bool with_head);

  ///@brief Create a linked list from a vector by tail insertion
  ///@param vec : Input number vector
  ///@param with_head : If true, there will be a head node
  ///@param head_val : Value of head node
  ///@return Root of created linked list
  ListNode * CreatByTailInsert(std::vector<int> const& vec, bool with_head, int head_val = 404);

};


#endif//C_PRACTICE_LINKEDLIST_H_INT
