/***************************************************
* File:   graph_aglo_int.h
* Brief:
* Author: kate
* Update: 2020/11/29.
***************************************************/


#ifndef C_PRACTICE_GRAPH_AGLO_INT_H
#define C_PRACTICE_GRAPH_AGLO_INT_H


#include <vector>
#include <iostream>

struct Arc {
  int val;        //Point to which vertex
  float weight;
  Arc * next;
  Arc(int v) : val{v}, weight{0.0f}, next{nullptr} {}
};

struct Vertex {
  int val;
  float info;
  Arc * first;
  Arc * tail;
  Vertex(int v) : val{v}, info{0.0f}, first{nullptr}, tail{nullptr} {}
};

struct Graph {
  int n_num;
  int e_num;
  std::vector<Vertex> vexes;
  Graph(): n_num{0}, e_num{0} {}
};

class GraphAlgo{
public:
  /// @brief Create an adjacent linked list graph from 2D vector
  /// @param input : Input 2D vector
  /// @param threshold : (Input) Weight of edge should be larger than threshold
  /// @return Graph
  Graph CreateAdjList(std::vector<std::vector<float>> const& input, float threshold);

  /// @brief Print adjacent linked list graph
  void PrintAdjGraph(Graph const & gf);

  /// @brief Depth first search
  /// @param gf : Graph
  /// @param v : Vertex
  /// @param vexes : Traversal result
  void DFS(Graph const& gf, int v, std::vector<int> &vexes);

  /// @brief Breadth first search(Matrix version)
  /// @param gf : Graph
  /// @param v : Vertex
  /// @param vexes : Traversal result
  void BFS_Matrix(std::vector<std::vector<float>> const& gf, float threshod, std::vector<int> &vexes);

  /// @brief Breadth first search
  /// @param gf : Graph
  /// @param v : Vertex
  /// @param vexes : Traversal result
  void BFS(Graph const& gf, int v, std::vector<int> &vexes);
};

#endif//C_PRACTICE_GRAPH_AGLO_INT_H
