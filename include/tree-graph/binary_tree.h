/***************************************************
* File:   binary_tree.h
* Brief:  Binary tree
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
  void Traversal(BTNode const * const rt, std::vector<int> &vec, TraversalType type);

private:
  /// @brief In-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  void in_order_traversal(BTNode const * const rt, std::vector<int> &vec);

  /// @brief Pre-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  void pre_order_traversal(BTNode const * const rt, std::vector<int> &vec);

  /// @brief Post-order traversal
  /// @param rt : Root of the binary tree
  /// @param vec : Traversal result
  void post_order_traversal(BTNode const * const rt, std::vector<int> &vec);
};

#endif//C_PRACTICE_BINARY_TREE_H
