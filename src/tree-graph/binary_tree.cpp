/***************************************************
* File:   binary_tree.cpp
* Brief:  Binary tree
* Author: kate
* Update: 2020/11/2.
***************************************************/


#include <queue>
#include <stack>
#include <iostream>

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
    pre_order_traversal(rt->left, vec);
    pre_order_traversal(rt->right, vec);
  }
}

void BinaryTree::post_order_traversal(BTNode const * const rt, std::vector<int> &vec) {
  if (nullptr != rt) {
    post_order_traversal(rt->left, vec);
    post_order_traversal(rt->right, vec);
    vec.push_back(rt->val);
  }
}

std::vector<std::vector<int> >  BinaryTree::levelOrder(BTNode* root) {
  std::vector<std::vector<int> > result;
  std::queue<std::pair<BTNode* ,int>> qu;
  if (root) {
    qu.push(std::make_pair(root, 0));
  }
  while(!qu.empty()) {
    auto cur_node{qu.front().first};
    if (cur_node->left) {
       qu.push(std::make_pair(cur_node->left,  qu.front().second + 1));
    }
    if (cur_node->right) {
      qu.push(std::make_pair(cur_node->right,  qu.front().second + 1));
    }
    if (result.size() == qu.front().second) {
      result.push_back({});
    }
    result.at(qu.front().second).push_back(cur_node->val);
    qu.pop();
  }
  return result;
}

BTNode* BinaryTree::GetAncestorPointer(BTNode* root, int o1, int o2) {
  if (root && (root->val != o1) && (root->val != o2)) {
    auto left{GetAncestorPointer(root->left,o1,o2)};
    auto right{GetAncestorPointer(root->right,o1,o2)};
    if (!left) {
      return right;
    }
    if (!right) {
      return left;
    }
    return root;
  }else{
    return root;
  }
}

int BinaryTree::lowestCommonAncestor(BTNode* root, int o1, int o2) {
   return GetAncestorPointer(root,o1,o2)->val;
}

std::vector<std::vector<int> > BinaryTree::zigzagLevelOrder(BTNode* root) {
  std::vector<std::vector<int> > result;
  std::stack<BTNode *> odd_level_st, even_level_st;
  if (root) {
    odd_level_st.push(root);
  }
  while (!even_level_st.empty() || !odd_level_st.empty()) {
    if (!even_level_st.empty()) {
      result.push_back(std::vector<int>());
      while (!even_level_st.empty()) {
        auto cur_node{even_level_st.top()};
        even_level_st.pop();
        result.back().push_back(cur_node->val);
        if (cur_node->right) {
          odd_level_st.push(cur_node->right);
        }
        if (cur_node->left) {
          odd_level_st.push(cur_node->left);
        }
      }
    }
    if (!odd_level_st.empty()) {
      result.push_back(std::vector<int>());
      while (!odd_level_st.empty()) {
        auto cur_node{odd_level_st.top()};
        odd_level_st.pop();
        result.back().push_back(cur_node->val);
        if (cur_node->left) {
          even_level_st.push(cur_node->left);
        }
        if (cur_node->right) {
          even_level_st.push(cur_node->right);
        }
      }
    }
  }
  return result;
}

void BinaryTree::create_complete_binary_tree(BTNode * root, int idx, std::vector<int> &input, int null_val) {
  if (root) {
    int len = input.size();
    if (2 * idx + 1 >= len || null_val == input.at(2 * idx + 1)) {
      root->left = nullptr;
    } else {
      root->left = new BTNode(input.at(2 * idx + 1));
      create_complete_binary_tree(root->left, 2 * idx + 1, input, null_val);
    }
    if (2 * idx + 2 >= len || null_val == input.at(2 * idx + 2)) {
      root->right = nullptr;
    } else {
      root->right = new BTNode(input.at(2 * idx + 2));
      create_complete_binary_tree(root->right, 2 * idx + 2, input, null_val);
    }
  }
}

BTNode * BinaryTree::CreateFromArray(std::vector<int> &input, int default_null_val) {
  BTNode * root{nullptr};
  int len = input.size();
  if (len > 0) {
    root = new BTNode(input.at(0));
    create_complete_binary_tree(root, 0, input, default_null_val);
  }
  return root;
}

BTNode * BinaryTree::creat_frm_preorder_inorder(
    std::vector<int> &pre_order, std::vector<int> &in_order, int from1, int to1,
    int from2, int to2) {
  auto root{new BTNode(pre_order.at(from1))};
  if (from1 == to1 && from2 == to2) {
    return root;
  } else {
    int i{from2};
    while (i <= to2 && in_order.at(i) != pre_order.at(from1)) {
      ++i;
    }
    if ((i - from2) > 0) {
      root->left = creat_frm_preorder_inorder(pre_order,in_order,from1+1,from1+i-from2,from2,i-1);
    }
    if ((to2 - i) > 0) {
      root->right = creat_frm_preorder_inorder(pre_order, in_order,from1+i-from2+1, to1, i+1, to2);
    }
    return root;
  }
}
