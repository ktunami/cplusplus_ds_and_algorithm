/***************************************************
* File:   array_problem_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/13.
***************************************************/
#include <vector>

#ifndef C_PRACTICE_ARRAY_PROBLEM_INT_H
#define C_PRACTICE_ARRAY_PROBLEM_INT_H

class ArrayProblem {
public:
  ///@brief Find the smallest k numbers (Nowcoder 119)
  ///@param input : The input array
  ///@param k : K nums
  ///@return The smallest k numbers
  std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k);

  ///@brief Merge sorted B to sorted A (Nowcoder 22)
  ///@param A : Array A
  ///@param m : Length of array A
  ///@param B : Array B
  ///@param n : Length of array B
  void merge(int A[], int m, int B[], int n) ;

  ///@brief Find two nums in a vector which add up to a given number (Nowcoder 61)
  ///@param numbers : Number vector
  ///@param target : The given number
  ///@return Index1 and index2 of the 2 number (Index1 < index2, start from 1)
  std::vector<int> twoSum(std::vector<int>& numbers, int target);

  ///@brief Find two nums in a vector which add up to a given number (Nowcoder 61)
  ///@param numbers : Number vector
  ///@param target : The given number
  ///@return Index1 and index2 of the 2 number (Index1 < index2, start from 1)
  std::vector<int> twoSum1(std::vector<int>& numbers, int target);

  ///@brief Return elements of a given matrix in spiral order (Nowcoder 38)
  ///@param matrix : The given matrix
  ///@return Number vector in spiral order
  std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix);

  ///@brief Find all combinations of 3 numbers in num which add up to 0 (Nowcoder 54)
  ///@param num : Input array
  ///@return All tuples that satisfy the requirement
  std::vector<std::vector<int> > threeSum(std::vector<int> &num);
}; //ArrayProblem

#endif//C_PRACTICE_ARRAY_PROBLEM_INT_H
