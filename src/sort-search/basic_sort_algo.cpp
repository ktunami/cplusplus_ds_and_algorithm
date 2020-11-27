/***************************************************
* File:   basic_sort_algo.cpp
* Brief:  Basic sort algorithm
* Author: kate
* Update: 2020/11/26.
***************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "basic_sort_algo.h"

void BasicSortAlgo::BubbleSort(std::vector<int> & input) {
  int last_pos = input.size() - 1;
  for (int i{0}; i < input.size(); ++i) {
    int current_pos = last_pos;
    for (int j{0}; j < current_pos; ++j) {
      if (input[j] > input[j+1]) {
        last_pos = j + 1;
        auto tmp{input[j+1]};
        input[j+1] = input[j];
        input[j] = tmp;
      }
    }
  }
}

void BasicSortAlgo::OddEvenSort(std::vector<int> & input) {
   bool need_sort{true};
   int len = input.size();
   while(need_sort) {
     need_sort = false;
     for (int i{1}; i < len && i+1 < len; i += 2) {
       if (input[i] > input[i+1]) {
         need_sort = true;
         auto tmp{input[i+1]};
         input[i+1] = input[i];
         input[i] = tmp;
       }
     }
     for (int i{0}; i < len && i+1 < len; i += 2) {
       if (input[i] > input[i+1]) {
         need_sort = true;
         auto tmp{input[i+1]};
         input[i+1] = input[i];
         input[i] = tmp;
       }
     }
   }
}

void BasicSortAlgo::QuickSort(std::vector<int> & input) {
  std::function<void(std::vector<int> &, int, int)> quick_sort_method;
  quick_sort_method = [&](std::vector<int> & vec, int from, int to) {
    if (from < to) {
      int i {from}, j{to};
      auto pivot{vec[i]};
      while(i < j) {
        while(i < j && vec[j] >= pivot) {
          --j;
        }
        if (i < j) {
          vec[i] = vec[j];
        }
        while(i < j && vec[i] <= pivot) {
          ++i;
        }
        if (i < j) {
          vec[j] = vec[i];
        }
      }
      vec[i] = pivot;
      quick_sort_method(vec, from, i-1);
      quick_sort_method(vec, i+1, to);
    }
  };
  quick_sort_method(input, 0, input.size()-1);
}

void BasicSortAlgo::SelectionSort(std::vector<int> & input) {
  for (int i{0}; i < input.size(); ++i) {
    auto largest{INT_MIN}, idx{0};
    for (int j{0}; j < input.size()-i; ++j) {
      if (input[j] > largest) {
        largest = input[j];
        idx = j;
      }
    }
    input[idx] = input[input.size()-i-1];
    input[input.size()-i-1] = largest;
  }
}

void BasicSortAlgo::InsertionSort(std::vector<int> & input) {
  for (int i{1}; i < input.size(); ++i) {
    auto val{input[i]}, j{i};
    while (j >=0 && val < input[j-1]) {
      input[j] = input[j-1];
      --j;
    }
    input[j] = val;
  }
}

void BasicSortAlgo::ShellSort(std::vector<int> & input) {
  int incre = input.size() >> 1;
  while (incre > 0) {
    for (int i{0}; i < incre; ++i) {
      for(int j{i + incre}; j < input.size(); j += incre) {
        auto val{input[j]}, k{j};
        while(k >= 0 && input[k - incre] > val) {
          input[k] = input[k - incre];
          k -= incre;
        }
        input[k] = val;
      }
    }
    incre >>= 1;
  }
}


void BasicSortAlgo::MergeSort(std::vector<int> & input) {
  std::function<void(std::vector<int> &,int, int, int)> merge_array;
  merge_array = [&](std::vector<int> & vec, int from,int mid, int to){
    std::vector<int> tmp;
    int i{from}, j{mid + 1};
    while (i <= mid && j <= to) {
      if (vec[i] <= vec[j]) {
        tmp.push_back(vec[i++]);
      } else {
        tmp.push_back(vec[j++]);
      }
    }
    while (i <= mid) {
      tmp.push_back(vec[i++]);
    }
    while (j <= to) {
      tmp.push_back(vec[j++]);
    }
    int idx = 0;
    for(int a{from}; a <= to; ++a) {
      vec[a] = tmp[idx++];
    }
  };
  std::function<void(std::vector<int> &, int, int)> merge;
  merge = [&](std::vector<int> & ve, int f, int t) {
    if (f != t) {
      int mid = (f + t) >> 1;
      merge(ve, f, mid);
      merge(ve, mid + 1, t);
      merge_array(ve,f,mid,t);
    }
  };
  merge(input, 0, input.size()-1);
}

void PPrintVector(std::vector<int> const & vec) {
  static int j = 1;
  std::cout << "group : " << j << std::endl;
  for (int i{0}; i < vec.size(); ++i) {
    std::cout << vec.at(i) << "--";
  }
  std::cout << std::endl;
  ++j;
}

void BasicSortAlgo::HeapSort(std::vector<int> & input) {
  std::function<void(std::vector<int> &, int, int)> adjust;
  adjust = [&](std::vector<int> &vec, int idx, int len) {
    int tmp = input[idx],father = idx, child = 2 * idx + 1;
    while (child < len) {
      if ((child + 1) < len && vec[child+1] > vec[child]) {
        ++child;
      }
      if (tmp < vec[child]) {
        vec[father] = vec[child];
        father = child;
        child = 2 * child + 1;
      } else {
        break;
      }
    }
    vec[father] = tmp;
  };
  for(int i=((input.size()>>1)-1); i>=0; --i) {
    adjust(input, i, input.size());
    PPrintVector(input);
  }
  for(int j=input.size()-1; j > 0; --j) {
    int tmp = input[j];
    input[j] = input[0];
    input[0] = tmp;
    adjust(input, 0, j);
  }
}
