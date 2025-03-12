// Has Cycle
//
// Write a function, hasCycle, that takes in an unordered map representing the
// adjacency list of a directed graph. The function should return a boolean
// indicating whether or not the graph contains a cycle.

// Complexity:
// Time: O(V + E) where V is the number of vertices and E is the number of
// edges. Space: O(V) for the recursion stack in the worst case.

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool detectCycle(const std::unordered_map<char, std::vector<char>>& graph,
                 std::unordered_set<char>& visiting,
                 std::unordered_set<char>& visited, char node) {
  if (visiting.count(node)) {
    return true;
  }

  if (visited.count(node)) {
    return false;
  }

  visiting.insert(node);

  // Ensure node exists in graph before accessing
  if (graph.find(node) != graph.end()) {
    for (const auto& neighbour : graph.at(node)) {
      if (detectCycle(graph, visiting, visited, neighbour)) {
        return true;
      }
    }
  }

  visiting.erase(node);
  visited.insert(node);

  return false;
}

bool hasCycle(const std::unordered_map<char, std::vector<char>>& graph) {
  std::unordered_set<char> visiting;
  std::unordered_set<char> visited;

  for (const auto& [node, _] : graph) {
    if (!visited.count(node)) {
      if (detectCycle(graph, visiting, visited, node)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  std::unordered_map<char, std::vector<char>> graph1{
      {'a', {'b'}}, {'b', {'c'}}, {'c', {'a'}}};
  assert(hasCycle(graph1));  // -> true

  std::unordered_map<char, std::vector<char>> graph2{
      {'a', {'b', 'c'}}, {'b', {'c'}}, {'c', {'d'}}, {'d', {}}};
  assert(!hasCycle(graph2));  // -> false

  std::unordered_map<char, std::vector<char>> graph3{
      {'a', {'b', 'c'}}, {'b', {}}, {'c', {}}, {'e', {'f'}}, {'f', {'e'}}};
  assert(hasCycle(graph3));  // -> true

  std::unordered_map<char, std::vector<char>> graph4{
      {'q', {'r', 's'}}, {'r', {'t', 'u'}}, {'s', {}}, {'t', {}},
      {'u', {}},         {'v', {'w'}},      {'w', {}}, {'x', {'w'}}};
  assert(!hasCycle(graph4));  // -> false

  std::unordered_map<char, std::vector<char>> graph5{
      {'a', {'b'}}, {'b', {'c'}}, {'c', {'a'}}, {'g', {}}};
  assert(hasCycle(graph5));  // -> true

  std::unordered_map<char, std::vector<char>> graph6{
      {'a', {'b'}}, {'b', {'c'}}, {'c', {'d'}}, {'d', {'b'}}};
  assert(hasCycle(graph6));  // -> true

  std::cout << "All tests passed!\n";
  return 0;
}
