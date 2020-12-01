/***************************************************
* File:   graph_aglo.cpp
* Brief:
* Author: kate
* Update: 2020/11/29.
***************************************************/

#include <queue>

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