/***************************************************
* File:   array_problem.h
* Brief:  Array problems
* Author: kate
* Update: 2020/11/13.
***************************************************/

#ifndef C_PRACTICE_ARRAY_PROBLEM_H
#define C_PRACTICE_ARRAY_PROBLEM_H

#include <vector>

///@brief Merge Intervals (Nowcoder 37) MergeIntevals
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

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

  ///@brief Find median from two sorted array (leetcode 4)
  ///@param nums1 : Vector 1
  ///@param nums2 : Vector 2
  ///@return Median
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);

  ///@brief Find the minimum positive number that disappeared (Nowcoder 30)
  ///@param arr : The input array
  ///@return The disappeared positive number
  int minNumberdisappered(std::vector<int>& arr);

  ///@brief Merge Intervals (Nowcoder 37)
  ///@param intervals : Input intervals
  ///@return Merged intervals
  std::vector<Interval> MergeIntevals(std::vector<Interval> &intervals);

  ///@brief Rotate N*N matrix  (Nowcoder 18)
  ///@param mat : Input matrix
  ///@param n : Size of matrix
  ///@return Rotated matrix
  std::vector<std::vector<int> > rotateMatrix(std::vector<std::vector<int> > mat, int n);

  ///@brief Count Length of max increasing subsequence in arr  (Nowcoder 95)
  ///@param arr : Input array
  ///@return length of subsequence
  int MLS(std::vector<int>& arr) ;


  ///@brief Compute inverse pairs in data  (Nowcoder 118)
  ///@param data : Input data
  ///@return Number of inverse pairs
  int InversePairs(std::vector<int> &data);

  ///@brief Compute inverse pairs in data  (Nowcoder 118)
  /// Should use merge sort, because merge sort is based on
  /// sorted arrays. If an array is sorted, no need to
  /// count inverse pairs one by one.
  ///@param data : Input data
  ///@return Number of inverse pairs
  int InversePairs2(std::vector<int> &data);

  ///@brief Find lost num (Nowcoder 101)
  ///@param a : Array
  ///@param aLen : Array length
  ///@return The lost num
  int FindLostNum(int* a, int aLen) ;

  ///@brief Find lost num (Nowcoder 101) use bit vec
  ///@param a : Array
  ///@param aLen : Array length
  ///@return The lost num
  int FindLostNum2(int* a, int aLen) ;

  ///@brief Right circular shift (Nowcoder 110)
  ///@param n ： Array length
  ///@param m : Shift times
  ///@param a : Input array
  ///@return Array after shift
  std::vector<int> RightCircularShift(int n, int m, std::vector<int>& a);

  ///@brief Resort array (Nowcoder 77)
  ///@param array : Input array
  void reOrderArray(std::vector<int> &array);

  ///@brief Matrix multiplication
  ///@param a : The first matrix
  ///@param b : The second matrix
  ///@return a * b
  std::vector<std::vector<int> >
      MatMal(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b);
}; //ArrayProblem
#endif//C_PRACTICE_ARRAY_PROBLEM_H
