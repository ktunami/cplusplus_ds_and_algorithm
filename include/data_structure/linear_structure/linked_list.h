/***************************************************
* File:   linked_list.h
* Brief:  About linked list
 * => linked list with cycle
 *    https://www.cnblogs.com/yorkyang/p/10876604.html
 *    https://blog.csdn.net/fynjy/article/details/47440049
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_LINKED_LIST_H
#define C_PRACTICE_LINKED_LIST_H

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
  std::vector<int> LinkedListTraversal(ListNode * const root, bool with_head);


  ///@brief Create a linked list from a vector by tail insertion
  ///@param vec : Input number vector
  ///@param with_head : If true, there will be a head node
  ///@param head_val : Value of head node
  ///@return Root of created linked list
  ListNode * CreatByTailInsert(std::vector<int> const& vec, bool with_head, int head_val = 404);

  ///@brief Reverse linked list (Nowcoder 78) Method2
  ///@param Original linked list
  ///@return Reversed linked list
  ListNode* ReverseList(ListNode* pHead) ;

  ///@brief Reverse linked list (Nowcoder 78) Method2
  ///@param Original linked list
  ///@return Reversed linked list
  ListNode* ReverseList2(ListNode* pHead) ;

  ///@brief Check if the linked list has cycle (Nowcoder 4)
  ///@param head : Root of linked list
  ///@return If has ring, return true
  bool hasCycle(ListNode *head);

  ///@brief Create linked list with cycle
  ///@param vec : Num vector
  ///@param pos : Index of the entry of the cycle (start from 0)
  ///@return  linked list with cycle
  ListNode * CreateCycleList(std::vector<int> const& vec, int pos);

  ///@brief Get the entry of cycle in linked list (Nowcoder 3)
  ///@param head :
  ListNode *detectCycle(ListNode *head);

};


#endif//C_PRACTICE_LINKED_LIST_H
