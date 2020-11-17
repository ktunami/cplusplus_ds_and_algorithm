/***************************************************
* File:   test_array_problem.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/13.
***************************************************/

#include <gtest/gtest.h>
#include <unordered_map>

#include "array_problem_int.h"
#include "common_test_method.h"


TEST(ArrayProblem, GetLeastNumbers_Solution) {
  std::vector<int> input_array{8,7,12,5,16,9,17,2,4,6};
  std::vector<int> expected_result{2,4,5,6};
  ArrayProblem arr;
  auto result{arr.GetLeastNumbers_Solution(input_array,4)};
  CheckIntVecEquality(result,expected_result);
}

TEST(ArrayProblem, merge) {
  int m = 5, n = 6;
  int A[15];
  int expected_result[] = {0,1,2,3,4,5,6,7,8,9,10};
  int tmp[] = {1,4,5,7,10};
  int B[] = {0,2,3,6,8,9};
  for (int i{0}; i < m; ++i) {
    A[i] = tmp[i];
  }
  ArrayProblem arr;
  arr.merge(A,m,B,n);
  for (int i{0}; i < m + n; ++i) {
    ASSERT_EQ(A[i], expected_result[i]);
  }
}

TEST(ArrayProblem, twoSum) {
  std::vector<int> input_array1{1,3,4,9};
  std::vector<int> input_array2{1,3,4,9};
  int target{7};
  std::vector<int> expected_result{2,3};
  ArrayProblem arr;
  auto result1{arr.twoSum(input_array1,target)};
  auto result2{arr.twoSum1(input_array2,target)};
  CheckIntVecEquality(result1,expected_result);
  CheckIntVecEquality(result2,expected_result);
}

TEST(ArrayProblem, spiralOrder) {
  int test_num{3};
  std::vector<std::vector<std::vector<int>>> input_arrays{
    {{1,2,3,4,5},  // first test
     {6,7,8,9,10},
     {11,12,13,14,15}},
    {{1,2,3},      // second test
     {4,5,6},
     {7,8,9},
     {10,11,12}},
    {{1,2,3,4},    // third test
     {5,6,7,8},
     {9,10,11,12},
     {13,14,15,16}}
  };
  std::vector<std::vector<int>> expected_results{
    {1,2,3,4,5,10,15,14,13,12,11,6,7,8,9},
    {1,2,3,6,9,12,11,10,7,4,5,8},
    {1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10}
  };
  ArrayProblem arr;
  for (int i{0}; i < test_num; ++i) {
    auto result{arr.spiralOrder(input_arrays.at(i))};
    CheckIntVecEquality(result,expected_results.at(i));
  }
}

TEST(ArrayProblem, threeSum) {
  int test_num{2};
  std::vector<std::vector<int>> input_arrays {
    {-10, 0, 10, 20, -10, -40},
    {0,1,1,2,3}
  };
  std::vector<std::vector<std::vector<int>>> all_expected_results {
    {{-10, 0, 10},
     {-10, -10, 20}},
    {}
  };
  ArrayProblem arr;
  for (int i{0}; i < test_num; ++i) {
    auto result{arr.threeSum(input_arrays.at(i))};
    auto expected_result{all_expected_results.at(i)};
    ASSERT_EQ(expected_result.size(), result.size());
    std::vector<int> flags(result.size(),0);
    for (int i{0}; i < result.size(); ++i) {
      std::sort(result.at(i).begin(), result.at(i).end());
      std::sort(expected_result.at(i).begin(), expected_result.at(i).end());
    }
    auto if_equal = [](std::vector<int> const& vec1, std::vector<int> const& vec2) {
      bool result{true};
      for (int m{0}; m < vec1.size(); ++m) {
        if (vec1.at(m) != vec2.at(m)) {
          result = false;
          break;
        }
      }
      return result;
    };
    for (int i{0}; i < result.size(); ++i) {
      bool this_round_pass{false};
      for (int j{0}; j < result.size(); ++j) {
        if (1 == flags.at(j)) {
          continue;
        }
        if (if_equal(result.at(i), expected_result.at(j))) {
          flags.at(j) = 1;
          this_round_pass = true;
          break;
        }
      }
      ASSERT_TRUE(this_round_pass);
    }
  }
}

TEST(ArrayProblem, findMedianSortedArrays) {
  std::vector<int> nums1{1,3};
  std::vector<int> nums2{2};
  ArrayProblem arr;
  double num = arr.findMedianSortedArrays(nums1, nums2);
  ASSERT_EQ(num, 2.00);
}


TEST(ArrayProblem, minNumberdisappered) {
  std::vector<int> nums{1,3};
  int result{2};
  ArrayProblem arr;
  double num = arr.minNumberdisappered(nums);
  ASSERT_EQ(num,result);
}


TEST(ArrayProblem, MergeIntevals) {
  std::vector<Interval> input{
    {10,30},{20,60},{80,100},{150,180}
  };
  std::vector<Interval> expected_output{
    {10,60},{80,100},{150,180}
  };
  ArrayProblem arr;
  auto result{arr.MergeIntevals(input)};
  ASSERT_EQ(expected_output.size(), result.size());
  for(int i{0}; i < result.size(); ++i) {
    ASSERT_EQ(expected_output.at(i).start, result.at(i).start);
    ASSERT_EQ(expected_output.at(i).end, result.at(i).end);
  }
}

TEST(ArrayProblem, MLS) {
  std::vector<int> input{100,4,200,1,3,2};
  ArrayProblem arr;
  ASSERT_EQ(arr.MLS(input), 4);
}

TEST(ArrayProblem, InversePairs) {
  std::vector<int> input1{100,4,200,1,3,2};
  std::vector<int> input2{100,4,200,1,3,2};
  ArrayProblem arr;
  auto result1{arr.InversePairs(input1)};
  auto result2{arr.InversePairs2(input2)};
  ASSERT_EQ(result1,result2);
}

TEST(ArrayProblem, RightCircularShift) {
  std::vector<int> input{1,2,3,4,5,6};
  std::vector<int> expected_result{5,6,1,2,3,4};
  ArrayProblem arr;
  auto vec{arr.RightCircularShift(6,2,input)};
  CheckIntVecEquality(vec, expected_result);
}

TEST(ArrayProblem, maxWater) {
  std::vector<int> input{3,1,2,5,2,4};
  ArrayProblem arr;
  int expected_result{5};
  ASSERT_EQ(expected_result,arr.maxWater(input));
}
