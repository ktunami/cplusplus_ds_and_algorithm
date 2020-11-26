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

std::vector<int> BinaryTree::GetRightSightView(std::vector<int>& xianxu, std::vector<int>& zhongxu) {
  auto root{creat_frm_preorder_inorder(xianxu, zhongxu, 0, zhongxu.size()-1, 0, zhongxu.size()-1)};
  std::queue<BTNode *> qu;
  std::vector<int> result;
  if (root) {
    qu.push(root);
    while(!qu.empty()) {
      int qu_size = qu.size();
      for(int i{0}; i < qu_size; ++i) {
        auto cur{qu.front()};
        qu.pop();
        if (cur->left) {
          qu.push(cur->left);
        }
        if (cur->right) {
          qu.push(cur->right);
        }
        if (i == (qu_size-1)) {
          result.push_back(cur->val);
        }
      }
    }
  }
  return result;
}

void BinaryTree::Mirror(BTNode *pRoot) {
  if (pRoot) {
    auto tmp{pRoot->left};
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
  }
}

int BinaryTree::maxDepth(BTNode* root) {
  if (root) {
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  } else {
    return 0;
  }
}

int BinaryTree::maxPathSum(BTNode* root) {
  int val{INT_MIN};
  std::function<int(BTNode* )> get_max_path_val;
  get_max_path_val = [&](BTNode * r) {
    if (r) {
      int left_max = std::max(0, get_max_path_val(r->left));
      int right_max = std::max(0, get_max_path_val(r->right));
      val = std::max(val, left_max + right_max + r->val);
      return std::max(left_max, right_max) + r->val;
    } else {
      return 0;
    }
  };
  get_max_path_val(root);
  return val;
}

BTNode* BinaryTree::KthNode(BTNode* pRoot, int k) {
  BTNode * result{nullptr};
  int num = 0;
  std::function<void(BTNode* )> find_kth;
  find_kth = [&](BTNode* r){
    if (r) {
      if (num < k) {
        find_kth(r->left);
      }
      ++num;
      if (num == k) {
        result = r;
      }
      if (num < k) {
        find_kth(r->right);
      }
    }
    return 0;
  };
  find_kth(pRoot);
  return result;
}

int BinaryTree::sumNumbers(BTNode* root) {
  int sum{0};
  std::queue<BTNode *> qu;
  if (root) {
    qu.push(root);
    while(!qu.empty()) {
      int qu_len = qu.size();
      for (int i{0}; i < qu_len; ++i) {
        auto cur{qu.front()};
        qu.pop();
        if (!cur->right && !cur->left) {
          sum += cur->val;
        }
        if(cur->left) {
          cur->left->val += 10 * cur->val;
          qu.push(cur->left);
        }
        if(cur->right) {
          cur->right->val += 10 * cur->val;
          qu.push(cur->right);
        }
      }
    }
  }
  return sum;
}

int BinaryTree::sumNumbers2(BTNode* root){
  int sum{0};
  std::function<void(BTNode *, int)> pre_order_traversal;
  pre_order_traversal = [&](BTNode * rt, int rt_num) {
    if (rt) {
      if (!rt->left && !rt->right) {
        sum += (rt_num * 10 + rt->val);
      }
      if (rt->left) {
        pre_order_traversal(rt->left, rt_num * 10 + rt->val);
      }
      if (rt->right) {
        pre_order_traversal(rt->right, rt_num * 10 + rt->val);
      }
    }
  };
  pre_order_traversal(root, 0);
  return sum;
}


bool BinaryTree::IsBalanced_Solution(BTNode* pRoot) {
  std::function<int(BTNode *)> get_depth;
  bool result{true};
  get_depth = [&] (BTNode * r) {
    if (result) {
      if (r) {
        int left_height = get_depth(r->left);
        int right_height = get_depth(r->right);
        int diff = left_height- right_height;
        if (diff >= 2 || diff <= -2) {
          result = false;
        }
        return 1 + std::max(left_height, right_height);
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  };
  get_depth(pRoot);
  return result;
}

std::vector<std::vector<int> > BinaryTree::pathSum(BTNode* root, int sum) {
  std::vector<std::vector<int> > result;
  std::vector<int> vec1;
  std::function<void(BTNode* rt, std::vector<int> path, int sm)> get_path;
  get_path = [&](BTNode* rt, std::vector<int> path, int sm) {
    if (rt) {
      path.push_back(rt->val);
      if (!rt->left && !rt->right && (sm+rt->val) == sum) {
        result.push_back(path);
      }
      if (rt->left) {
        get_path(rt->left, path, sm+rt->val);
      }
      if (rt->right) {
        get_path(rt->right, path, sm+rt->val);
      }
    }
  };
  get_path(root, vec1, 0);
  return result;
}

std::vector<bool> BinaryTree::judgeIt(BTNode* root) {
  bool is_binary_search_tree{true}, is_balanced{true};
  std::vector<bool> result;
  int last_num{INT_MIN};
  std::function<void(BTNode *, int &)> check_binary_search_tree;
  check_binary_search_tree = [&](BTNode * rt, int & last) {
    if (rt) {
      check_binary_search_tree(rt->left, last);
      if (rt->val > last) {
        last = rt->val;
      } else {
        is_binary_search_tree = false;
      }
      check_binary_search_tree(rt->right, last);
    }
  };
  std::function<int(BTNode *)> check_is_balanced;
  check_is_balanced = [&](BTNode * rt) {
    if (rt) {
      int left = check_is_balanced(rt->left);
      int right = check_is_balanced(rt->right);
      int diff = left - right;
      if (diff > 1 || diff < -1) {
        is_balanced = false;
      }
      return std::max(left,right) + 1;
    } else {
      return 0;
    }
  };
  check_binary_search_tree(root, last_num);
  result.push_back(is_binary_search_tree);
  check_is_balanced(root);
  result.push_back(is_balanced);
  return result;
}

void PrintVector(std::vector<int> const & vec) {
  static int j = 1;
  std::cout << "group : " << j << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << "--";
  }
  std::cout << std::endl;
  ++j;
}

bool BinaryTree::isSymmetric(BTNode* root) {
  std::function<bool(BTNode *, BTNode *)> check_left_right_symmetric;
  check_left_right_symmetric = [&](BTNode * left, BTNode * right) {
    if (!left && !right) {
      return true;
    } else if (!left || !right || (left->val != right->val)) {
      return false;
    } else {
      return check_left_right_symmetric(left->left, right->right) &&
          check_left_right_symmetric(left->right, right->left);
    }
  };
  return root ? check_left_right_symmetric(root->left, root->right) : true;
}

bool BinaryTree::isContains(BTNode* root1, BTNode* root2) {
  BTNode * r1{nullptr};
  std::function<void(BTNode *, BTNode *)> find_root;
  find_root = [&](BTNode * rt, BTNode * point) {
    if (rt) {
      if (rt->val == point->val) {
        r1 = rt;
      } else {
        find_root(rt->left, point);
        find_root(rt->right, point);
      }
    }
  };
  std::function<bool(BTNode *, BTNode *)> check_equality;
  check_equality = [&](BTNode * a1, BTNode * a2) {
    if (!a1 && !a2) {
      return true;
    }else if (!a1 || !a2 || a1->val != a2->val) {
      return false;
    } else {
      return check_equality(a1->left, a2->left) && check_equality(a1->right, a2->right);
    }
  };

  if (!root2) {
    return root1 ? false : true;
  } else {
    find_root(root1, root2);
    return r1 ? check_equality(r1, root2) : false;
  }
}

BTNode* BinaryTree::mergeTrees(BTNode* t1, BTNode* t2) {
  if (!t1 && !t2) {
    return nullptr;
  }
  if (!t1) {
    return t2;
  }
  if (!t2) {
    return t1;
  }
  t1->val += t2->val;
  t1->left = mergeTrees(t1->left, t2->left);
  t1->right = mergeTrees(t1->right, t2->right);
  return t1;
}

int BinaryTree::CompleteTreeNodeNum(BTNode* head) {
  if (head) {
    BTNode * left{head->left};
    BTNode * right{head->right};
    int left_level{0}, right_level{0};
    while (left) {
      ++left_level;
      left = left->left;
    }
    while (right) {
      ++right_level;
      right = right->right;
    }
    if (left_level == right_level) {
      return (1 << (left_level + 1)) - 1;
    } else {
      return CompleteTreeNodeNum(head->left) + CompleteTreeNodeNum(head->right) + 1;
    }
  } else {
    return 0;
  }
}

std::vector<int> BinaryTree::findError(BTNode* root) {
  bool find_first{true};
  int pre{INT_MIN}, small{INT_MIN}, mid{INT_MIN}, large{INT_MIN};
  std::function<void(BTNode *)> find_node_ptr;
  find_node_ptr = [&](BTNode * rt) {
    if (rt) {
      find_node_ptr(rt->left);
      if (rt->val >= pre) {
        if ((!find_first) && (pre == INT_MIN)) {
          large = rt->val;
        }
        pre = rt->val;
      } else {
        if (find_first) {
          small = pre;
          mid = rt->val;
          pre = INT_MIN;
          find_first = false;
        } else {
          large = rt->val;
        }
      }
      find_node_ptr(rt->right);
    }
  };
  find_node_ptr(root);
  if (mid > large && mid < small) {
    return std::vector<int>{large, small};
  } else if (small < mid) {
    return std::vector<int>{large, mid};
  } else {
    return std::vector<int>{mid, small};
  }
}