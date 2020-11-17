/***************************************************
* File:   bitwise_operation_int.h
* Brief:
* Author: kate
* Update: 2020/11/17.
***************************************************/


#ifndef C_PRACTICE_BITWISE_OPERATION_INT_H
#define C_PRACTICE_BITWISE_OPERATION_INT_H

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
};

#endif//C_PRACTICE_BITWISE_OPERATION_INT_H
