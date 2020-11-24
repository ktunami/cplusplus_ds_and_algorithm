/***************************************************
* File:   binary_tree_int.h
* Brief:  For gtest
 * About common ancestor : https://blog.csdn.net/qq_33323162/article/details/52371293
* Author: kate
* Update: 2020/11/2.
***************************************************/

#ifndef C_PRACTICE_BINARY_TREE_H
#define C_PRACTICE_BINARY_TREE_H

#include <vector>

/// @brief Binary tree node
struct BTNode {
  int val;
  BTNode *left;
  BTNode *right;
  BTNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
  /// @brief Traversal type
  enum class TraversalType {
    PRE_ORDER = 0,
    IN_ORDER = 1,
    POST_ORDER = 2
  };

  /// @brief Traversal of a binary tree
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  /// @param type : Traversal type
  static void Traversal(BTNode const * const rt, std::vector<int> &vec, TraversalType type);

  /// @brief In-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  static void in_order_traversal(BTNode const * const rt, std::vector<int> &vec);

  /// @brief Pre-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  static void pre_order_traversal(BTNode const * const rt, std::vector<int> &vec);

  /// @brief Post-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  static void post_order_traversal(BTNode const * const rt, std::vector<int> &vec);

  /// @brief Level order (Nowcoder 15)
  static std::vector<std::vector<int> > levelOrder(BTNode* root);

  /// @brief Get ancestor pointer (Nowcoder 102)
  /// @param root : Input tree
  /// @param o1 : Value 1
  /// @param o2 : Value 2
  /// @return Pointer of common ancestor of o1 and o2
  static BTNode* GetAncestorPointer(BTNode* root, int o1, int o2);

  /// @brief Find common ancestor (Nowcoder 102)
  /// @param root : Input tree
  /// @param o1 : Element 1
  /// @param o2 : Element 2
  /// @return The common ancestor
  static int lowestCommonAncestor(BTNode* root, int o1, int o2);

  /// @brief Zigzag level order traversal (Nowcoder 14)
  /// @param root : Input tree
  /// @return Traversal result
  static std::vector<std::vector<int> > zigzagLevelOrder(BTNode* root);

  /// @brief Create complete binary tree from input vector
  static void create_complete_binary_tree(BTNode * root, int idx, std::vector<int> &input, int null_val);

  /// @brief Create a binary tree from an array
  /// @param input : Input array
  /// @param default_null_val : Null value
  /// @return Root of binary tree
  static BTNode * CreateFromArray(std::vector<int> &input, int default_null_val = 0);

  /// @brief Create binary tree from pre-order traversal and in-order traversal vector
  /// @param pre_order :  pre-order vector
  /// @param in_order : in-order vector
  /// @param from1 : lower bound index of pre-order vector
  /// @param to1 : upper bound index of pre-order vector
  /// @param from2 : lower bound index of in-order vector
  /// @param to2 : upper bound index of in-order vector
  /// @return Root of the tree
  static BTNode * creat_frm_preorder_inorder(
    std::vector<int> &pre_order, std::vector<int> &in_order, int from1, int to1,
    int from2, int to2);
};

#endif//C_PRACTICE_BINARY_TREE_H
