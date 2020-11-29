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
  template<class T>
  static T * CreateFromArray(std::vector<int> &input, int default_null_val = 0) {
    T * root{nullptr};
    int len = input.size();
    if (len > 0) {
      root = new T(input.at(0));
      create_complete_binary_tree<T>(root, 0, input, default_null_val);
    }
    return root;
  }

  /// @brief Traversal of a binary tree
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  /// @param type : Traversal type
  template<class T>
  static void Traversal(T const * const rt, std::vector<int> &vec, TraversalType type) {
    vec.clear();
    switch (type) {
      case TraversalType::IN_ORDER :
        in_order_traversal<T>(rt, vec);
        break;
      case TraversalType::POST_ORDER :
        post_order_traversal<T>(rt, vec);
        break;
      case TraversalType::PRE_ORDER :
        pre_order_traversal<T>(rt, vec);
        break;
    }
  }

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

  /// @brief Check if the tree is balanced (Nowcoder 62)
  /// @param pRoot : Root of tree
  /// @return if balanced, return true
  static bool IsBalanced_Solution(BTNode* pRoot);

  /// @brief Get path from root to leaves whose values sum up to a given value (Nowcoder 8)
  /// @param root : Binary tree
  /// @param sum : The given value;
  static std::vector<std::vector<int> > pathSum(BTNode* root, int sum);

  /// @brief Judge if a binary tree is a binary search tree and a complete binary tree (Nowcoder 60)
  /// @param root : Binary tree
  /// @return Judge result
  static std::vector<bool> judgeIt(BTNode* root);

  /// @brief Check if the tree is symmetric (剑指offer 28)
  /// @param root : Input tree
  /// @return True if the tree is symmetric
  static bool isSymmetric(BTNode* root);

  /// @brief Check if root1 contains root2
  static bool isContains(BTNode* root1, BTNode* root2);

  /// @brief Merge trees (Nowcoder 117)
  /// @param t1 : Tree1
  /// @param t2 : Tree2
  /// @return Merged tree
  static BTNode* mergeTrees(BTNode* t1, BTNode* t2);

  /// @brief Compute number of tree nodes (Nowcoder 84)
  /// @param head : Input tree
  /// @return Number of tree node
  static int CompleteTreeNodeNum(BTNode* head);

  /// @brief Find errors in binary search tree (Nowcoder 58)
  /// @param root : Input tree
  /// @return The wrong values
  static std::vector<int> findError(BTNode* root);

private:
  /// @brief In-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  template<class T>
  static void in_order_traversal(T const * const rt, std::vector<int> &vec) {
    if (nullptr != rt) {
      in_order_traversal(rt->left, vec);
      vec.push_back(rt->val);
      in_order_traversal(rt->right, vec);
    }
  }

  /// @brief Pre-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  template<class T>
  static void pre_order_traversal(T const * const rt, std::vector<int> &vec) {
    if (nullptr != rt) {
      vec.push_back(rt->val);
      pre_order_traversal(rt->left, vec);
      pre_order_traversal(rt->right, vec);
    }
  }

  /// @brief Post-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  template<class T>
  static void post_order_traversal(T const * const rt, std::vector<int> &vec) {
    if (nullptr != rt) {
      post_order_traversal(rt->left, vec);
      post_order_traversal(rt->right, vec);
      vec.push_back(rt->val);
    }
  }

  /// @brief Create complete binary tree from input vector
  template<class T>
  static void create_complete_binary_tree(T * root, int idx, std::vector<int> &input, int null_val) {
    if (root) {
      int len = input.size();
      if (2 * idx + 1 >= len || null_val == input.at(2 * idx + 1)) {
        root->left = nullptr;
      } else {
        root->left = new T(input.at(2 * idx + 1));
        create_complete_binary_tree(root->left, 2 * idx + 1, input, null_val);
      }
      if (2 * idx + 2 >= len || null_val == input.at(2 * idx + 2)) {
        root->right = nullptr;
      } else {
        root->right = new T(input.at(2 * idx + 2));
        create_complete_binary_tree(root->right, 2 * idx + 2, input, null_val);
      }
    }
  }

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
