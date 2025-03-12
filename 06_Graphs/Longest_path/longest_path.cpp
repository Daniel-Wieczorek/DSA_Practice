// Longest Path
//
// Write a function, longestPath, that takes in an adjacency list for a directed
// acyclic graph. The function should return the length of the longest path
// within the graph. A path may start and end at any two nodes. The length of a
// path is considered the number of edges in the path, not the number of nodes.

// Complexity:
// Time: O(V + E), where V is the number of vertices and E is the number of
// edges. Space: O(V), for storing memoized distances.

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

// Helper function using memoized DFS to compute longest path
int dfs(const std::unordered_map<char, std::vector<char>>& graph,
        std::unordered_map<char, int>& distance, char current) {
  if (distance.count(current)) {
    return distance[current];
  }

  int max_distance = 0;
  for (const auto& neighbor : graph.at(current)) {
    max_distance = std::max(max_distance, 1 + dfs(graph, distance, neighbor));
  }

  distance[current] = max_distance;
  return max_distance;
}

int longestPath(const std::unordered_map<char, std::vector<char>>& graph) {
  std::unordered_map<char, int> distance;
  int max_path = 0;  // Changed from `std::numeric_limits<int>::min()` to `0`

  for (const auto& [node, _] : graph) {
    max_path = std::max(max_path, dfs(graph, distance, node));
  }

  return max_path;
}

int main() {
  std::unordered_map<char, std::vector<char>> graph1{
      {'a', {'c', 'b'}}, {'b', {'c'}}, {'c', {}}};
  assert(longestPath(graph1) == 2);

  std::unordered_map<char, std::vector<char>> graph2{
      {'a', {'c', 'b'}},      {'b', {'c'}}, {'c', {}},    {'q', {'r'}},
      {'r', {'s', 'u', 't'}}, {'s', {'t'}}, {'t', {'u'}}, {'u', {}}};
  assert(longestPath(graph2) == 4);

  std::unordered_map<char, std::vector<char>> graph3{
      {'h', {'i', 'j', 'k'}}, {'g', {'h'}}, {'i', {}}, {'j', {}}, {'k', {}},
      {'x', {'y'}},           {'y', {}}};
  assert(longestPath(graph3) == 2);

  std::unordered_map<char, std::vector<char>> graph4{
      {'a', {'b'}}, {'b', {'c'}}, {'c', {}}, {'e', {'f'}},
      {'f', {'g'}}, {'g', {'h'}}, {'h', {}}};
  assert(longestPath(graph4) == 3);

  std::cout << "All tests passed!\n";
  return 0;
}
