/***************************************************
* File:   common_test_method.h
* Brief:  Common functions for gtest
* Author: kate
* Update: 2020/11/14.
***************************************************/


#ifndef C_PRACTICE_COMMON_TEST_METHOD_H
#define C_PRACTICE_COMMON_TEST_METHOD_H

#include <vector>
#include <iostream>

///@brief Check if two integral vectors are equal
///@param vec1 : vector 1
///@param vec2 : vector 2
void CheckIntVecEquality(std::vector<int> const& vec1, std::vector<int> const& vec2);

///@brief Check if two 2D integral vectors are equal
///@param vec1 : vector 1
///@param vec2 : vector 2
void Check2DIntVecEquality(std::vector<std::vector<int>> const& vec1, std::vector<std::vector<int>> const& vec2);

///@brief Print integral vector
///@param vec : Input vector
void PrintVector(std::vector<int> const& vec);

///@brief Print 2D integral vector
///@param vec : Input vector
void Print2DVector(std::vector<std::vector<int>> const& vec);

///@brief Compute hash code of a vector
///@param vec : Input vector
///@return Hash code
long long RSHashForVector(std::vector<int> const& vec);

///@brief Check if two 2D vectors contains the same members
///@param vec1 : Vector 1
///@param vec2 : Vector 2
///@param need_sort : If true, means to sort subarray first
void Check2DSameMembers(
    std::vector<std::vector<int>> & vec1,
    std::vector<std::vector<int>> & vec2,
    bool need_sort);

#endif//C_PRACTICE_COMMON_TEST_METHOD_H
