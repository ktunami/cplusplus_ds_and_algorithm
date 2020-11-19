/***************************************************
* File:   bitwise_operation.h
* Brief:  Bitwise operation
 * https://blog.csdn.net/qq_41318400/article/details/107724948
* Author: kate
* Update: 2020/11/17.
***************************************************/


#ifndef C_PRACTICE_BITWISE_OPERATION_H
#define C_PRACTICE_BITWISE_OPERATION_H

#include <vector>

class BitOp {
public:
  ///@brief Exchange two integers
  ///@param a : Integer 1
  ///@param b : Integer 2
  static void ExchangeTwoIntegers(int &a, int &b);

  ///@brief Add two integers
  ///@param a : Integer 1
  ///@param b : Integer 2
  static int add(int a, int b);

  ///@brief Add two integers (None recursive)
  ///@param a : Integer 1
  ///@param b : Integer 2
  static int add1(int a, int b);

  ///@brief Minus
  ///@param a : Integer 1
  ///@param b : Integer 2
  ///@return a - b
  static int minus(int a, int b);

  ///@brief Multiply
  ///@param a : Integer 1
  ///@param b : Integer 2
  ///@return a * b
  static int multiply(int a, int b);

  ///@brief Comparision
  ///@param a : Integer 1
  ///@param b : Integer 2
  ///@return True if a < b
  static bool ComparisionOfTwoIntegers(int a, int b);

  ///@brief Count ones
  ///@param a : Input bit vector
  ///@return Number of 1s
  static int CountOnes(int a);

  ///@brief Count bits number in [0 ~ num] (leetcode 338)
  ///@param num : Input number
  ///@return array of bits
  static std::vector<int> countBits(int num);

  ///@brief Count bits number in [0 ~ num] (leetcode 338)
  ///@param num : Input number
  ///@return array of bits
  static std::vector<int> countBits1(int num);

  ///@brief Bitwise AND of Numbers Range (leetcode 201)
  ///@param m : Small number
  ///@param n : Large number
  ///@return The "and" result
  static int rangeBitwiseAnd(int m, int n);

  ///@brief Find all subsets (leetcode 08.04)
  ///@param nums : input set
  ///@return All subsets
  static std::vector<std::vector<int>> subsets(std::vector<int>& nums);

  ///@brief Compute hamming distance between any two numbers in nums (leetcode 477)
  ///@param nums : Input vector
  ///@return Total distance
  static int totalHammingDistance(std::vector<int>& nums);

  ///@brief Find the number that only appears once
  ///  all other numbers appear 3times (leetcode 137)
  ///@param nums : Input vector
  ///@return The single number
  static int singleNumber(std::vector<int>& nums);

  ///@brief Reverse bit pattern
  ///@param a : Input num
  ///@return Reversed number
  static std::uint32_t reverseBits(std::uint32_t a);
};

#endif//C_PRACTICE_BITWISE_OPERATION_H
