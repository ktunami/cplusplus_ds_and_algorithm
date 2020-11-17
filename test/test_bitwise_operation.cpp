/***************************************************
* File:   test_bitwise_operation.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/17.
***************************************************/


#include <gtest/gtest.h>

#include "bitwise_operation_int.h"

TEST(BitOp, ExchangeTwoIntegers) {
  int a = 3, b = 5;
  BitOp::ExchangeTwoIntegers(a,b);
  ASSERT_EQ(a,5);
  ASSERT_EQ(b,3);
}

TEST(BitOp, ComparisionOfTwoIntegers) {
  int a = 3, b = 5;
  ASSERT_TRUE(BitOp::ComparisionOfTwoIntegers(a,b));
}

TEST(BitOp, basic_operations) {
  int a = 3, b = 5;
  ASSERT_EQ(8,BitOp::add(a,b));
  ASSERT_EQ(8,BitOp::add1(a,b));
  ASSERT_EQ(2,BitOp::minus(b,a));
  ASSERT_EQ(-2,BitOp::minus(a,b));
  ASSERT_EQ(0,BitOp::minus(0,0));
  ASSERT_EQ(15, BitOp::multiply(a,b));
  ASSERT_EQ(2, BitOp::CountOnes(b));
}

