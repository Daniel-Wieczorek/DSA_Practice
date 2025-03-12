// Connected Components Count
//
// Write a function, connectedComponentsCount, that takes in an unordered map
// representing the adjacency list for an undirected graph. The function should
// return the number of connected components within the graph.

// Complexity:
// Time: O(V + E) where V is the number of vertices and E is the number of
// edges. Space: O(V) due to the visited set.

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using IntGraph = std::unordered_map<int, std::vector<int>>;

void explore(const IntGraph& graph, std::unordered_set<int>& visited,
             int current) {
  if (visited.count(current)) return;

  visited.insert(current);
  for (const auto& neighbor : graph.at(current)) {
    explore(graph, visited, neighbor);
  }
}

int connectedComponentsCount(const IntGraph& graph) {
  std::unordered_set<int> visited;
  int count = 0;

  for (const auto& [node, _] : graph) {
    if (!visited.count(node)) {
      explore(graph, visited, node);
      ++count;
    }
  }

  return count;
}

int main() {
  {
    IntGraph graph{{0, {8, 1, 5}}, {1, {0}},    {5, {0, 8}}, {8, {0, 5}},
                   {2, {3, 4}},    {3, {2, 4}}, {4, {3, 2}}};
    assert(connectedComponentsCount(graph) == 2);
  }

  {
    IntGraph graph{{1, {2}}, {2, {1, 8}}, {6, {7}},
                   {9, {8}}, {7, {6, 8}}, {8, {9, 7, 2}}};
    assert(connectedComponentsCount(graph) == 1);
  }

  {
    IntGraph graph{{3, {}},  {4, {6}}, {6, {4, 5, 7, 8}}, {8, {6}},
                   {7, {6}}, {5, {6}}, {1, {2}},          {2, {1}}};
    assert(connectedComponentsCount(graph) == 3);
  }

  {
    IntGraph graph;
    assert(connectedComponentsCount(graph) == 0);
  }

  std::cout << "All tests passed!\n";
  return 0;
}
