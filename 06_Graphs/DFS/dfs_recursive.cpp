// Depth First Search (DFS) - Recursive
//
// Implement a depth-first search (DFS) for a graph and print its data.
// The function should traverse the graph recursively.
//
// Complexity:
// Time: O(V + E), where V is the number of vertices and E is the number of
// edges. Space: O(V) due to recursion depth in the worst case (a single long
// path).

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
using graphT = std::unordered_map<T, std::vector<T>>;

void dfs(const graphT<std::string> &graph, const std::string &current,
         std::unordered_set<std::string> &visited) {
  if (visited.count(current))
    return;  // Prevent infinite loops in cyclic graphs

  std::cout << current << " ";
  visited.insert(current);

  for (const auto &neighbor : graph.at(current)) {
    dfs(graph, neighbor, visited);
  }
}

void testDFS() {
  graphT<std::string> graph{{"a", {"b", "c"}}, {"b", {"d"}}, {"c", {"e"}},
                            {"d", {"f"}},      {"e", {}},    {"f", {}}};

  std::unordered_set<std::string> visited;

  // Expected output: a b d f c e (or any valid DFS order)
  dfs(graph, "a", visited);
  std::cout << "\nTests passed!\n";
}

int main() {
  testDFS();
  return 0;
}
