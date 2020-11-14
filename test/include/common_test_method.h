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
void CheckIntVecEquality(std::vector<int> &vec1, std::vector<int> &vec2);

///@brief Print integral vector
///@param vec : Input vector
void PrintVector(std::vector<int> &vec);

#endif//C_PRACTICE_COMMON_TEST_METHOD_H
