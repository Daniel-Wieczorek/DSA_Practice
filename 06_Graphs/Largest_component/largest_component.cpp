// Largest Component
//
// Write a function, largestComponent, that takes in an unordered_map
// representing the adjacency list of an undirected graph. The function should
// return the size of the largest connected component in the graph.

// Complexity:
// Time: O(V + E), where V is the number of vertices and E is the number of
// edges. Each node and edge is processed once in a DFS traversal. Space: O(V),
// due to the visited set and recursion stack (in worst case).

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using IntGraph = std::unordered_map<int, std::vector<int>>;

int explore(const IntGraph& graph, std::unordered_set<int>& visited, int node) {
  if (visited.count(node)) {
    return 0;
  }
  visited.insert(node);

  int size = 1;
  for (int neighbor : graph.at(node)) {
    size += explore(graph, visited, neighbor);
  }

  return size;
}

int largestComponent(const IntGraph& graph) {
  std::unordered_set<int> visited;
  int largest = 0;

  for (const auto& pair : graph) {
    int size = explore(graph, visited, pair.first);
    if (size > largest) {
      largest = size;
    }
  }

  return largest;
}

int main() {
  {
    IntGraph graph{{0, {8, 1, 5}}, {1, {0}},    {5, {0, 8}}, {8, {0, 5}},
                   {2, {3, 4}},    {3, {2, 4}}, {4, {3, 2}}};
    assert(largestComponent(graph) == 4);
  }

  {
    IntGraph graph{{1, {2}}, {2, {1, 8}}, {6, {7}},
                   {9, {8}}, {7, {6, 8}}, {8, {9, 7, 2}}};
    assert(largestComponent(graph) == 6);
  }

  {
    IntGraph graph{{3, {}},  {4, {6}}, {6, {4, 5, 7, 8}}, {8, {6}},
                   {7, {6}}, {5, {6}}, {1, {2}},          {2, {1}}};
    assert(largestComponent(graph) == 5);
  }

  {
    IntGraph graph;
    assert(largestComponent(graph) == 0);
  }

  std::cout << "All tests passed!\n";
  return 0;
}
