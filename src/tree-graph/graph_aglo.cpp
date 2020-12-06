/***************************************************
* File:   graph_aglo.cpp
* Brief:
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include <queue>
#include <float.h>
#include <set>

#include "graph_aglo.h"

Graph GraphAlgo::CreateAdjList(std::vector<std::vector<float>> const& input, float threshold) {
  Graph gf;
  int row_num = input.size();
  if (row_num) {
    int col_num = input.at(0).size();
    if (row_num == col_num) {
      gf.n_num = row_num;
      for (int k{0}; k < row_num; ++k) {
        gf.vexes.push_back(Vertex(k));
      }
      for (int i{0}; i < row_num; ++i) {
        for (int j{0}; j < row_num; ++j) {
          if (input[i][j] > threshold) {
            auto new_arc{new Arc(j)};
            if (nullptr == gf.vexes[i].first) {
              gf.vexes[i].first = new_arc;
              gf.vexes[i].tail = new_arc;
            } else {
              gf.vexes[i].tail->next = new_arc;
              gf.vexes[i].tail = gf.vexes[i].tail->next;
            }
            ++gf.e_num;
            new_arc->weight = input[i][j];
          }
        }
      }
    }
  }
  return gf;
}

void GraphAlgo::PrintAdjGraph(Graph const & gf) {
  std::cout << "Vertex num: " << gf.n_num << std::endl;
  std::cout << "Edge num: " << gf.e_num << std::endl;
  std::cout << "Adjacent linked list: " << std::endl;
  for (int i{0}; i < gf.vexes.size(); ++i) {
    std::cout << gf.vexes.at(i).val << " => ";
    auto p{gf.vexes.at(i).first};
    while(p) {
      std::cout << p->val << ", ";
      p = p->next;
    }
    std::cout << std::endl;
  }
}

void GraphAlgo::DFS(Graph const& gf, int v, std::vector<int> &vexes) {
   std::vector<bool> visited(gf.n_num, false);
   std::function<void(Graph const&, int)> dfs_algo;
   dfs_algo = [&](Graph const& graph, int vex) {
     vexes.push_back(vex);
     visited[vex] = true;
     auto arc{graph.vexes[vex].first};
     while(arc) {
       if (false == visited[arc->val]) {
         dfs_algo(graph, arc->val);
       }
       arc = arc->next;
     }
   };
   vexes.clear();
   dfs_algo(gf, v);
}

void GraphAlgo::BFS(Graph const& gf, int v, std::vector<int> &vexes){
  std::vector<bool> visit(gf.n_num, false);
  std::queue<int> qu;
  vexes.push_back(v);
  visit[v] = true;
  qu.push(v);
  while (!qu.empty()) {
    auto cur{qu.front()};
    qu.pop();
    auto arc{gf.vexes[cur].first};
    while (arc) {
      if (false == visit[arc->val]) {
        vexes.push_back(arc->val);
        visit[arc->val] = true;
        qu.push(arc->val);
      }
      arc = arc->next;
    }
  }
}

void GraphAlgo::BFS_Matrix(std::vector<std::vector<float>> const& gf, float threshod, std::vector<int> &vexes) {
  std::vector<bool> visit(gf.size(), false);
  for (int i{0}; i < gf.size(); ++i) {
    if (false == visit[i]) {
      visit[i] = true;
      vexes.push_back(i);
      std::queue<int> qu;
      qu.push(i);
      while (!qu.empty()) {
        auto tp{qu.front()};
        qu.pop();
        for (int j{0}; j < gf.size(); ++j) {
          if (gf[tp][j] > threshod && false == visit[j]) {
            visit[j] = true;
            vexes.push_back(j);
            qu.push(j);
          }
        }
      }
    }
  }
}

void GraphAlgo::Prim(std::vector<std::vector<float>> const& gf, std::vector<int> &vertex) {
  if (gf.size()) {
    std::vector<float> lowcost(gf.at(0).begin(), gf.at(0).end());
    std::vector<bool> visited(gf.size(), false);
    int current_vertex{0};
    visited[0] = true;
    vertex.push_back(0);
    auto find_smallest_weight = [&]() {
      float min{FLT_MAX - 5};
      for (int i{0}; i < lowcost.size(); ++i) {
        if (false == visited[i] && lowcost[i] < min) {
          min = lowcost[i];
          current_vertex = i;
        }
      }
    };
    auto update_lowcost = [&](int v) {
      for (int i{0}; i < lowcost.size(); ++i) {
        if (false == visited[i] && lowcost[i] > gf.at(v).at(i)) {
          lowcost[i] = gf.at(v).at(i);
        }
      }
    };
    for (int i{0}; i < gf.size() - 1; ++i) {
      find_smallest_weight();
      visited[current_vertex] = true;
      vertex.push_back(current_vertex);
      update_lowcost(current_vertex);
    }
  }
}

void GraphAlgo::Kruskal(std::vector<std::vector<float>> const& gf, std::vector<Edge> &edges) {
  std::vector<Edge> edge_set;
  int vertex_num = gf.size();
  std::vector<int> disjoint_set;
  for (int i{0}; i < vertex_num; ++i) {
    for (int j{i}; j < vertex_num; ++j) {
      if (gf.at(i).at(j) < (FLT_MAX - 4)) {
        Edge eg;
        eg.a = i;
        eg.b = j;
        eg.weight = gf.at(i).at(j);
        edge_set.push_back(eg);
      }
    }
    disjoint_set.push_back(i);
  }
  auto get_root = [&](int v) {
    while (disjoint_set[v] != v) {
      v = disjoint_set[v];
    }
    return v;
  };
  std::sort(edge_set.begin(), edge_set.end(), [](Edge & e1, Edge & e2) {
    return e1.weight < e2.weight;
  });
  for (int i{0}; i < edge_set.size(); ++i) {
    int m = get_root(edge_set[i].a);
    int n = get_root(edge_set[i].b);
    if (m != n) {
      disjoint_set[m] = n;
      edges.push_back(edge_set.at(i));
    }
  }
}

void GraphAlgo::Dijkstra(std::vector<std::vector<float>> const& gf, int v0,
    std::vector<int> &path, std::vector<float> &weight) {
  std::vector<bool> visited(gf.size(), false);
  visited[v0] = true;
  path.clear();
  weight.clear();
  for (auto num : gf.at(v0)) {
    weight.push_back(num);
    if (num < (FLT_MAX - 4)) {
      path.push_back(v0);
    } else {
      path.push_back(-1);
    }
  }
  for (int j{1}; j < gf.size(); ++j) {
    int cur_vertex = -1;
    float lowweight = FLT_MAX - 4;
    for (int i{0}; i < weight.size(); ++i) {
      if (false == visited[i] && lowweight > weight.at(i)) {
        lowweight = weight.at(i);
        cur_vertex = i;
      }
    }
    if (cur_vertex < 0) {
      break;
    } else {
      visited[cur_vertex] = true;
      for (int i{0}; i < weight.size(); ++i) {
        if (false == visited[i] && weight[i] > weight[cur_vertex] + gf.at(cur_vertex).at(i)) {
          weight[i] = weight[cur_vertex] + gf.at(cur_vertex).at(i);
          path[i] = cur_vertex;
        }
      }
    }
  }
}

void GraphAlgo::DijkstraGetPath(std::vector<int> const& path, int v0, int vu, std::vector<int> &result) {
  if (v0 == vu) {
    result.push_back(v0);
    return;
  } else {
    DijkstraGetPath(path, v0, path.at(vu), result);
    result.push_back(vu);
  }
}

std::vector<std::vector<int>> GraphAlgo::Floyd(std::vector<std::vector<float>> const& gf) {
  std::vector<std::vector<float>> weight;
  for (auto vec : gf) {
    weight.push_back(vec);
  }
  std::vector<std::vector<int>> path(gf.size(),std::vector<int>(gf.size(), -1));
  for (int k{0}; k < gf.size(); ++k) {
    for (int i{0}; i < gf.size(); ++i) {
      for (int j{0}; j < gf.size(); ++j) {
        if(weight[i][j] > weight[i][k] + weight[k][j]) {
           weight[i][j] = weight[i][k] + weight[k][j];
           path[i][j] = k;
        }
      }
    }
  }
  return path;
}

void GraphAlgo::FloydGetPath(std::vector<std::vector<int>> const& input, int v0, int vu, std::vector<int> &path) {
  auto mid{input.at(v0).at(vu)};
  if (mid == -1) {
    path.push_back(v0);
  } else {
    FloydGetPath(input,v0,mid,path);
    FloydGetPath(input,mid,vu,path);
  }
}

std::vector<int> GraphAlgo::TopologicalSort(Graph &gf) {
  for (auto &vex : gf.vexes) {
    auto arc{vex.first};
    while(arc) {
      ++gf.vexes[arc->val].count;
      arc = arc->next;
    }
  }
  std::queue<int> qu;
  std::vector<int> result;
  for(int i{0}; i < gf.n_num; ++i) {
    if (0 == gf.vexes[i].count) {
      qu.push(i);
      result.push_back(i);
    }
  }
  while(!qu.empty()) {
    int qu_len = qu.size();
    for (int i{0}; i < qu_len; ++i) {
      auto cur{qu.front()};
      qu.pop();
      auto arc{gf.vexes[cur].first};
      while(arc) {
        --gf.vexes[arc->val].count;
        if (0 == gf.vexes[arc->val].count) {
          qu.push(arc->val);
          result.push_back(arc->val);
        }
        arc = arc->next;
      }
    }
  }
  return result;
}