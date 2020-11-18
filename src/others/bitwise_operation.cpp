/***************************************************
* File:   bitwise_operation.cpp
* Brief:
* Author: kate
* Update: 2020/11/17.
***************************************************/

#include "bitwise_operation.h"

#include <iostream>

void BitOp::ExchangeTwoIntegers(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}

int BitOp::add(int a, int b) {
  int carry = (a & b) << 1;
  int add_without_carry = a ^ b;
  if(carry) {
    return add(add_without_carry, carry);
  } else {
    return add_without_carry;
  }
}

int BitOp::add1(int a, int b) {
  int carry = (a & b) << 1;
  int add_without_carry = a ^ b;
  while(carry) {
    int new_carry = (carry & add_without_carry) << 1;
    add_without_carry = carry ^ add_without_carry;
    carry = new_carry;
  }
  return add_without_carry;
}

int BitOp::minus(int a, int b) {
  return add1(a,add1(1,~b));
}

int BitOp::multiply(int a, int b) {
  int result{0};
  int count{0};
  while (b) {
    if (b & 1) {
      result += add1(a,b << count);
    }
    ++count;
    b >>= 1;
  }
  return result;
}

bool BitOp::ComparisionOfTwoIntegers(int a, int b){
  return (a - b) & 0x80000000;
}

int BitOp::CountOnes(int a) {
  int result{0};
  while (a) {
    ++result;
    a = a & (a - 1);
  }
  return result;
}


std::vector<int> BitOp::countBits(int num) {
  std::vector<int> result(1,0);
  if (num == 0) {
    return result;
  } else if (num == 1) {
    result.push_back(1);
    return result;
  } else {
    result.push_back(1);
    int count{-1}, tmp_num{num};
    while(tmp_num) {
      ++count;
      tmp_num >>= 1;
    }
    std::vector<int> last_vec(1,1);
    int sum = 1, pos = 1;
    while (count > 0) {
      --count;
      sum += (pos << 1);
      pos <<= 1;
      std::vector<int> cur_vec(last_vec.begin(),last_vec.end());
      for (auto &ele : last_vec) {
        ++ele;
      }
      cur_vec.insert(cur_vec.end(),last_vec.begin(),last_vec.end());
      if (sum > num) {
        int offset = pos - sum + num;
        result.insert(result.end(),cur_vec.begin(),cur_vec.begin() + offset);
      } else {
        result.insert(result.end(),cur_vec.begin(),cur_vec.end());
      }
      last_vec.swap(cur_vec);
    }
    return result;
  }
}

std::vector<int> BitOp::countBits1(int num) {
  std::vector<int> result(num+1,0);
  for (int i{1}; i <= num; ++i) {
    result[i] = result[i >> 1] + (i & 1);
  }
  return result;
}

int BitOp::rangeBitwiseAnd(int m, int n) {
  int result{m & n};
  int tmp_result{result};
  int cur_bit{tmp_result & (-tmp_result)};
  while (cur_bit) {
    if (result & cur_bit) {
      if ((n - m) >= (cur_bit + 1)) {
        result &= (~cur_bit);
      }
    }
    tmp_result &= (tmp_result-1);
    cur_bit = tmp_result & (-tmp_result);
  }
  return result;
}

std::vector<std::vector<int>> BitOp::subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> result(1, std::vector<int>());
  for (int i{0}; i < nums.size(); ++i) {
    std::vector<std::vector<int>> tmp(result.begin(), result.end());
    for(auto &vec : tmp) {
      vec.push_back(nums.at(i));
    }
    result.insert(result.end(),tmp.begin(),tmp.end());
  }
  return result;
}
