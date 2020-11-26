/***************************************************
* File:   basic_sort_algo_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/26.
***************************************************/


#ifndef C_PRACTICE_BASIC_SORT_ALGO_INT_H
#define C_PRACTICE_BASIC_SORT_ALGO_INT_H

#include <vector>

class BasicSortAlgo{
public:
  static void BubbleSort(std::vector<int> & input);

  static void OddEvenSort(std::vector<int> & input);

  static void QuickSort(std::vector<int> & input);

  static void SelectionSort(std::vector<int> & input);

  static void InsertionSort(std::vector<int> & input);

  static void ShellSort(std::vector<int> & input);

  static void MergeSort(std::vector<int> & input);

  static void HeapSort(std::vector<int> & input);

  static void CountingSort(std::vector<int> & input);

  static void RadixSort(std::vector<int> & input);

  static void BucketSort(std::vector<int> & input);
};

#endif//C_PRACTICE_BASIC_SORT_ALGO_INT_H
