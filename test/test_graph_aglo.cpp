/***************************************************
* File:   test_graph_aglo.cpp
* Brief:
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include <gtest/gtest.h>

#include "graph_aglo_int.h"
#include "common_test_method.h"

void CheckAdjacentGraph(std::vector<std::vector<float>> const& matrix, Graph const & gf, float threshold) {
  if (matrix.size() == 0) {
    ASSERT_EQ(gf.n_num,0);
    ASSERT_EQ(gf.e_num,0);
    ASSERT_EQ(gf.vexes.size(),0);
  } else {
    ASSERT_EQ(matrix.at(0).size(), matrix.size());
    ASSERT_EQ(gf.n_num, matrix.size());
    int count{0};
    for (int i{0}; i < gf.n_num; ++i) {
      auto arc{gf.vexes[i].first};
      for (int j{0}; j < gf.n_num; ++j) {
         if (matrix[i][j] > threshold) {
           ASSERT_TRUE(arc);
           ASSERT_EQ(j, arc->val);
           ASSERT_EQ(matrix[i][j],arc->weight);
           arc = arc->next;
           ++count;
         }
      }
    }
    ASSERT_EQ(gf.e_num, count);
  }
}

TEST(GraphAlgo, CreateAdjList) {
  GraphAlgo graph_algo;
  std::vector<std::vector<float>> input {
    {0,1,0,1,1},
    {0,0,1,0,1},
    {1,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
  };
  auto gf{graph_algo.CreateAdjList(input, 0.0f)};
  CheckAdjacentGraph(input, gf, 0.0f);
}

TEST(GraphAlgo, DFS) {
  GraphAlgo graph_algo;
  std::vector<std::vector<float>> input {
    {0,1,0,1,1},
    {0,0,1,0,1},
    {1,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
  };
  auto gf{graph_algo.CreateAdjList(input, 0.0f)};
  std::vector<int> result;
  std::vector<int> expected_result{0,1,2,4,3};
  graph_algo.DFS(gf,0, result);
  CheckIntVecEquality(result, expected_result);
}

TEST(GraphAlgo, BFS) {
  GraphAlgo graph_algo;
  std::vector<std::vector<float>> input {
    {0,1,0,1,1},
    {0,0,1,0,1},
    {1,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
  };
  auto gf{graph_algo.CreateAdjList(input, 0.0f)};
  std::vector<int> result1, result2;
  std::vector<int> expected_result{0,1,3,4,2};
  graph_algo.BFS(gf,0, result1);
  graph_algo.BFS_Matrix(input, 0.0f, result2);
  CheckIntVecEquality(result1, expected_result);
  CheckIntVecEquality(result2, expected_result);
}