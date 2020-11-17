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