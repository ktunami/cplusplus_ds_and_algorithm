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

struct Edge {
  int a;           // start
  int b;           // end
  float weight;
};

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

  /// @brief Prim algorithm (Minimum spanning tree)
  /// @param gf : Input graph
  /// @param edges : Output vertex of minimum spanning tree
  void Prim(std::vector<std::vector<float>> const& gf,  std::vector<int> &vertex);

  /// @brief Kruskal algorithm (Minimum spanning tree)
  /// @param gf : Input graph
  /// @param edges : Output edges of minimum spanning tree
  void Kruskal(std::vector<std::vector<float>> const& gf, std::vector<Edge> &edges);

  /// @brief Dijkstra algorithm
  /// @param gf : Input graph
  /// @param v0 : Start from v0
  /// @param path : Last step in each shortest path to a certain vertex
  /// @param weight : The weight of each path
  void Dijkstra(std::vector<std::vector<float>> const& gf, int v0,
      std::vector<int> &path, std::vector<float> &weight);

  /// @brief Get path from v0 to vu in Dijkstra result
  /// @param path : Input path
  /// @param v0 : From v0
  /// @param vu : To vu
  /// @param result : final path
  void DijkstraGetPath(std::vector<int> const& path, int v0, int vu, std::vector<int> &result);

  /// @brief Floyd algorithm
  /// @param gf : Input graph
  /// @return  Shortest path
  std::vector<std::vector<int>> Floyd(std::vector<std::vector<float>> const& gf);

  /// @brief  Get path from v0 to vu in Floyd result
  /// @param input : Input path
  /// @param v0 : From v0
  /// @param vu : To vu
  /// @param path : Output path
  void FloydGetPath(std::vector<std::vector<int>> const& input, int v0, int vu, std::vector<int> &path);
};

#endif//C_PRACTICE_GRAPH_AGLO_INT_H
