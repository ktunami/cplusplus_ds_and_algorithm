/***************************************************
* File:   test_basic_sort_algo.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/26.
***************************************************/

#include <gtest/gtest.h>

#include "basic_sort_algo_int.h"
#include "common_test_method.h"

TEST(BasicSortAlgo, BubbleSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::BubbleSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, OddEvenSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::OddEvenSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, QuickSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::QuickSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, SelectionSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::SelectionSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, InsertionSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::InsertionSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, ShellSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::ShellSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, MergeSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::MergeSort(input);
  CheckIntVecEquality(expected_result, input);
}

TEST(BasicSortAlgo, HeapSort){
  std::vector<int> input{2,1,3,6,4,5,8,9,7};
  std::vector<int> expected_result{1,2,3,4,5,6,7,8,9};
  BasicSortAlgo::HeapSort(input);
  CheckIntVecEquality(expected_result, input);
}

