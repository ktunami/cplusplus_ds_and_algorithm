/***************************************************
* File:   test_graph_aglo.cpp
* Brief:  For gtest
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include <gtest/gtest.h>
#include <float.h>

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

TEST(GraphAlgo, Prim) {
  std::vector<std::vector<float>> gf{
    {FLT_MAX,5,1,2,FLT_MAX},
    {5,FLT_MAX,3,FLT_MAX,4},
    {1,3,FLT_MAX,6,2},
    {2,FLT_MAX,6,FLT_MAX,3},
    {FLT_MAX,4,2,3,FLT_MAX}
  };
  GraphAlgo gfag;
  std::vector<int> result;
  std::vector<int> expected_result{0,2,3,4,1};
  gfag.Prim(gf,result);
  CheckIntVecEquality(expected_result, result);
}

TEST(GraphAlgo, Kruskal) {
  std::vector<std::vector<float>> gf{
    {FLT_MAX,5,1,2,FLT_MAX},
    {5,FLT_MAX,3,FLT_MAX,4},
    {1,3,FLT_MAX,6,2},
    {2,FLT_MAX,6,FLT_MAX,3},
    {FLT_MAX,4,2,3,FLT_MAX}
  };
  GraphAlgo gfag;
  std::vector<Edge> result;
  gfag.Kruskal(gf,result);
  float whole_weight{0.0f};
  ASSERT_EQ(result.size(), 4);
  for (int i{0}; i < result.size(); ++i) {
    whole_weight += result[i].weight;
  }
  ASSERT_EQ(whole_weight, 8);
}


TEST(GraphAlgo, Dijkstra) {
  std::vector<std::vector<float>> gf{
    {FLT_MAX, 4,6,6,FLT_MAX,FLT_MAX,FLT_MAX},
    {FLT_MAX,FLT_MAX,1,FLT_MAX,7,FLT_MAX,FLT_MAX},
    {FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,6,4,FLT_MAX},
    {FLT_MAX,FLT_MAX,2,FLT_MAX,FLT_MAX,5,FLT_MAX},
    {FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,6},
    {FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,1,FLT_MAX,8},
    {FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX}
  };
  std::vector<int> path;
  std::vector<float> weight;
  GraphAlgo gfag;
  gfag.Dijkstra(gf,0,path,weight);
  std::vector<int> expected_path{-1,0,1,0,5,2,4};
  CheckIntVecEquality(path, expected_path);
}

TEST(GraphAlgo, DijkstraGetPath) {
  GraphAlgo gfag;
  std::vector<int> input_paths{-1, 0, 1, 0, 5, 2, 4};
  int v0 = 0;
  int vu = 6;
  std::vector<int> expected_path{0, 1, 2, 5, 4, 6};
  std::vector<int> path;
  gfag.DijkstraGetPath(input_paths,v0,vu,path);
  CheckIntVecEquality(path, expected_path);
}

TEST(GraphAlgo, GraphAlgo) {
  std::vector<std::vector<float>> gf{
    {0,5,FLT_MAX,7},
    {FLT_MAX,0,4,2},
    {3,3,0,2},
    {FLT_MAX,FLT_MAX,1,0}
  };
  GraphAlgo gfag;
  std::vector<std::vector<int>> expected_result{
    {-1,-1,3,-1},
    {3,-1,3,-1},
    {-1,-1,-1,-1},
    {2,2,-1,-1}
  };
  Check2DIntVecEquality(expected_result,gfag.Floyd(gf));
}

TEST(GraphAlgo, FloydGetPath) {
  std::vector<std::vector<int>> input{
    {-1,-1,3,-1},
    {3,-1,3,-1},
    {-1,-1,-1,-1},
    {2,2,-1,-1}
  };
  std::vector<int> result;
  std::vector<int> expected_result{1,3,2};
  GraphAlgo gfag;
  gfag.FloydGetPath(input,1,0,result);
  CheckIntVecEquality(result,expected_result);
}

TEST(GraphAlgo, TopologicalSort) {
  GraphAlgo graph_algo;
  std::vector<std::vector<float>> input {
    {0,1,1,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,1,1,0},
    {0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,1,0,1},
    {0,0,0,0,0,0,0}
  };
  auto gf{graph_algo.CreateAdjList(input, 0.0f)};
  std::vector<int> expected_result{0,1,3,2,5,4,6};
  auto result{graph_algo.TopologicalSort(gf)};
  CheckIntVecEquality(result, expected_result);
}