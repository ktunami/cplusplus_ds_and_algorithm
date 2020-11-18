/***************************************************
* File:   test_bitwise_operation.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/17.
***************************************************/


#include <gtest/gtest.h>
#include <unordered_set>

#include "bitwise_operation_int.h"
#include "common_test_method.h"

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


TEST(BitOp, countBits) {
  int num = 9;
  auto vec{BitOp::countBits(num)};
  std::vector<int> re{0,1,1,2,1,2,2,3,1,2};
  CheckIntVecEquality(re, vec);
}

TEST(BitOp, rangeBitwiseAnd) {
  ASSERT_EQ(4,BitOp::rangeBitwiseAnd(5,7));
  ASSERT_EQ(0,BitOp::rangeBitwiseAnd(0,1));
}

TEST(BitOp, subsets) {
  std::vector<int> input_vec{1,2,3};
  auto result{BitOp::subsets(input_vec)};
  std::vector<std::vector<int>> expected_result{{},
    {1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
  std::unordered_set<long long> expected_result_set;
  for (auto const& vec : expected_result) {
    expected_result_set.insert(RSHashForVector(vec));
  }
  int count{0};
  for (auto const& vec : result) {
    auto n{RSHashForVector(vec)};
    ASSERT_TRUE(expected_result_set.find(n) != expected_result_set.end());
    ++count;
  }
}

TEST(BitOp, totalHammingDistance) {
  std::vector<int> vec{4, 14, 2};
  ASSERT_EQ(6,BitOp::totalHammingDistance(vec));
}