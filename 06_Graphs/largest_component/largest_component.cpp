// Largest Component
//
// Write a function, largestComponent, that takes in an unordered_map
// representing the adjacency list of an undirected graph. The function should
// return the size of the largest connected component in the graph.

// Complexity:
// Time: O(V + E) where V is the number of vertices and E is the number of
// edges. Space: O(V) due to the visited set and recursion depth.

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using IntGraph = std::unordered_map<int, std::vector<int>>;

int exploreComponent(const IntGraph& graph, std::unordered_set<int>& visited,
                     int current) {
  if (visited.count(current)) {
    return 0;
  }

  visited.insert(current);
  int size = 1;

  for (int neighbor : graph.at(current)) {
    size += exploreComponent(graph, visited, neighbor);
  }

  return size;
}

int largestComponent(const IntGraph& graph) {
  std::unordered_set<int> visited;
  int largest = 0;

  for (const auto& [node, _] : graph) {
    int size = exploreComponent(graph, visited, node);
    if (size > largest) {
      largest = size;
    }
  }

  return largest;
}

int main() {
  IntGraph graph1{{0, {8, 1, 5}}, {1, {0}},    {5, {0, 8}}, {8, {0, 5}},
                  {2, {3, 4}},    {3, {2, 4}}, {4, {3, 2}}};
  assert(largestComponent(graph1) == 4);

  IntGraph graph2{{1, {2}}, {2, {1, 8}}, {6, {7}},
                  {9, {8}}, {7, {6, 8}}, {8, {9, 7, 2}}};
  assert(largestComponent(graph2) == 6);

  IntGraph graph3{{3, {}},  {4, {6}}, {6, {4, 5, 7, 8}}, {8, {6}},
                  {7, {6}}, {5, {6}}, {1, {2}},          {2, {1}}};
  assert(largestComponent(graph3) == 5);

  IntGraph graph4;
  assert(largestComponent(graph4) == 0);

  std::cout << "All tests passed!\n";
  return 0;
}
