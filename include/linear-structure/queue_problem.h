/***************************************************
* File:   queue_problem.h
* Brief:  Queue problems
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

  /// @brief Count sub arrays which satisfy the following formula:
  /// max(arr[i…j]) - min(arr[i…j]) <= num
  /// @param vec : Input vector
  /// @param num : Threshold
  /// @return Number of sub arrays
  int getNum(std::vector<int> &vec, int num);

};
#endif//C_PRACTICE_QUEUE_PROBLEM_H
