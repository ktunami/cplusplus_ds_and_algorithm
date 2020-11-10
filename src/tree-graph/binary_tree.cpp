/***************************************************
* File:   binary_tree.cpp
* Brief:  Binary tree
* Author: kate
* Update: 2020/11/2.
***************************************************/

#include "binary_tree.h"

void BinaryTree::Traversal(BTNode const * const rt, std::vector<int> &vec, TraversalType type) {
  vec.clear();
  switch (type) {
    case TraversalType::IN_ORDER :
      in_order_traversal(rt, vec);
      break;
    case TraversalType::POST_ORDER :
      post_order_traversal(rt, vec);
      break;
    case TraversalType::PRE_ORDER :
      pre_order_traversal(rt, vec);
      break;
  }
}

void BinaryTree::in_order_traversal(BTNode const * const rt, std::vector<int> &vec) {
  if (nullptr != rt) {
    in_order_traversal(rt->left, vec);
    vec.push_back(rt->val);
    in_order_traversal(rt->right, vec);
  }
}


void BinaryTree::pre_order_traversal(BTNode const * const rt, std::vector<int> &vec) {
  if (nullptr != rt) {
    vec.push_back(rt->val);
    in_order_traversal(rt->left, vec);
    in_order_traversal(rt->right, vec);
  }
}

void BinaryTree::post_order_traversal(BTNode const * const rt, std::vector<int> &vec) {
  if (nullptr != rt) {
    in_order_traversal(rt->left, vec);
    in_order_traversal(rt->right, vec);
    vec.push_back(rt->val);
  }
}