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
  ///@param head : Root of linked list
  ///@return The entry of cycle, if no cycle, return nullptr
  ListNode * detectCycle(ListNode *head);

  ///@brief N members form a circle, del the mth element
  /// each time, and start from the next place till only
  /// one member remains in the circle (Nowcoder 132)
  ///https://blog.csdn.net/likerxu/article/details/44891609
  int ysf(int n, int m) ;

  ///@brief Merge ordered linked list (Nowcoder 33)
  ///@param l1 : The 1st list
  ///@param l2 : The 2nd list
  ///@return Merged linked list
  ListNode * mergeTwoLists(ListNode* l1, ListNode* l2);

  ///@brief Find the first common node (Nowcoder 66)
  ///@param pHead1 : The 1st list
  ///@param pHead2 : The 2nd list
  ///@return The first common node
  ListNode * FindFirstCommonNode(ListNode * pHead1, ListNode * pHead2);

  ///@brief Reverse Nodes in k-Group (by using stack)
  ///@param head : Root of linked list
  ///@param k : k-Group
  ///@return Reversed group
  ListNode * reverseKGroup(ListNode * head, int k);

  ///@brief Reverse Nodes in k-Group (In place method)
  ///@param head : Root of linked list
  ///@param k : k-Group
  ///@return Reversed group
  ListNode * reverseKGroupInplace(ListNode * head, int k);

  ///@brief Delete duplicate elements in the linked list
  ///@param head : Root of linked list
  ///@return Linked list after processed
  ListNode* deleteDuplicates(ListNode* head);

  ///@brief Remove the Nth element from the end
  ///@param head : Root of the lined list
  ///@param n : the nth element from the end
  ///@return The processed linked list
  ListNode* removeNthFromEnd(ListNode* head, int n);

};


#endif//C_PRACTICE_LINKED_LIST_H
