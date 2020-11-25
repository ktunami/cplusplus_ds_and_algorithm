/***************************************************
* File:   binary_tree.h
* Brief:  Binary tree
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

  /// @brief Create a binary tree from an array
  /// @param input : Input array
  /// @param default_null_val : Null value
  /// @return Root of binary tree
  static BTNode * CreateFromArray(std::vector<int> &input, int default_null_val = -100);

  /// @brief Traversal of a binary tree
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  /// @param type : Traversal type
  static void Traversal(BTNode const * const rt, std::vector<int> &vec, TraversalType type);

  /// @brief Level order traversal (Nowcoder 15)
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

  /// @brief Create binary tree from pre-order traversal and in-order traversal vector
  /// then get the right sight view of the binary tree (Nowcoder 136)
  /// @param xianxu : pre-order traversal vector;
  /// @param zhongxu : in-order traversal vector;
  /// @return Right sight view of the binary tree
  static std::vector<int> GetRightSightView(std::vector<int>& xianxu, std::vector<int>& zhongxu);

  /// @brief Get mirror of a binary tree (Nowcoder 72)
  /// @param pRoot : Input tree
  static void Mirror(BTNode *pRoot);

  /// @brief Get max depth of a binary tree (Nowcoder 13)
  /// @param root : Input tree
  static int maxDepth(BTNode* root);

  /// @brief Find the maximum path sum (Leetcode 124)
  static int maxPathSum(BTNode* root);

  /// @brief Find the kth node in a binary search tree (Nowcoder 81)
  /// @param pRoot : Root of the tree
  /// @param k : the kth number
  /// @return The pointer of the kth number
  static BTNode* KthNode(BTNode* pRoot, int k);

  /// @brief Get the sum of number formed from all root to leaves (Nowcoder 5)
  /// level traversal method
  static int sumNumbers(BTNode* root);

  /// @brief Get the sum of number formed from all root to leaves (Nowcoder 5)
  /// pre-order traversal method
  static int sumNumbers2(BTNode* root);

  /// @brief Check if the tree is balanced
  /// @param pRoot : Root of tree
  /// @return if balanced, return true
  static bool IsBalanced_Solution(BTNode* pRoot);

  /// @brief Get path from root to leaves whose values sum up to a given value
  /// @param root : Binary tree
  /// @param sum : The given value;
  static std::vector<std::vector<int> > pathSum(BTNode* root, int sum);

private:
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

  /// @brief Create complete binary tree from input vector
  static void create_complete_binary_tree(BTNode * root, int idx, std::vector<int> &input, int null_val);

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
