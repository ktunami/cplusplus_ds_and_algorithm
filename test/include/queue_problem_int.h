/***************************************************
* File:   queue_problem_int.h
* Brief:  For gtest
* Author: kate
* Update: 2020/11/3.
***************************************************/


#ifndef C_PRACTICE_QUEUE_PROBLEM_H
#define C_PRACTICE_QUEUE_PROBLEM_H

#include <vector>

class QueueProblem {
public:

  /*  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
      Output: [3,3,5,5,6,7]
      Explanation:
      Window position                Max
      ---------------               -----
      [1  3  -1] -3  5  3  6  7       3
       1 [3  -1  -3] 5  3  6  7       3
       1  3 [-1  -3  5] 3  6  7       5
       1  3  -1 [-3  5  3] 6  7       5
       1  3  -1  -3 [5  3  6] 7       6
       1  3  -1  -3  5 [3  6  7]      7
   * */
  /// @brief Max slide window (leetcode 239)
  /// @param nums : Input vector
  /// @param k    : Window size
  /// @return Max element in each window
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
};
#endif//C_PRACTICE_QUEUE_PROBLEM_H