// Shortest Path
//
// Write a function, shortestPath, that takes in a vector of edges for an
// undirected graph and two nodes (nodeA, nodeB). The function should return
// the length of the shortest path between A and B. Consider the length as
// the number of edges in the path, not the number of nodes. If there is no
// path between A and B, then return -1. You can assume that A and B exist
// as nodes in the graph.

// Complexity:
// Time: O(V + E) where V is the number of nodes and E is the number of edges.
// Space: O(V + E) for storing the adjacency list.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
using Graph = std::unordered_map<T, std::vector<T>>;
using StringGraph = Graph<std::string>;

StringGraph makeGraph(
    const std::vector<std::tuple<std::string, std::string>> &edges) {
  StringGraph graph;
  for (const auto &[a, b] : edges) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

int shortestPath(const std::vector<std::tuple<std::string, std::string>> &edges,
                 const std::string &nodeA, const std::string &nodeB) {
  StringGraph graph = makeGraph(edges);
  std::queue<std::pair<std::string, int>> queue;
  queue.emplace(nodeA, 0);
  std::unordered_set<std::string> visited{nodeA};

  while (!queue.empty()) {
    auto [node, distance] = queue.front();
    queue.pop();
    if (node == nodeB) return distance;

    for (const auto &neighbor : graph[node]) {
      if (!visited.count(neighbor)) {
        visited.insert(neighbor);
        queue.emplace(neighbor, distance + 1);
      }
    }
  }
  return -1;
}

int main() {
  std::vector<std::tuple<std::string, std::string>> edges1{
      {"w", "x"}, {"x", "y"}, {"z", "y"}, {"z", "v"}, {"w", "v"}};
  assert(shortestPath(edges1, "w", "z") == 2);
  assert(shortestPath(edges1, "y", "x") == 1);

  std::vector<std::tuple<std::string, std::string>> edges2{
      {"a", "c"}, {"a", "b"}, {"c", "b"}, {"c", "d"},
      {"b", "d"}, {"e", "d"}, {"g", "f"}};
  assert(shortestPath(edges2, "a", "e") == 3);
  assert(shortestPath(edges2, "e", "c") == 2);
  assert(shortestPath(edges2, "b", "g") == -1);

  std::vector<std::tuple<std::string, std::string>> edges3{
      {"c", "n"}, {"c", "e"}, {"c", "s"}, {"c", "w"}, {"w", "e"}};
  assert(shortestPath(edges3, "w", "e") == 1);
  assert(shortestPath(edges3, "n", "e") == 2);

  std::cout << "All tests passed!\n";
  return 0;
}
