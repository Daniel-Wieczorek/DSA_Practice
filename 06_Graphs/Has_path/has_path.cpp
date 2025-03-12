// Has Path
//
// Write a function, hasPath, that takes in an unordered map representing the
// adjacency list of a directed acyclic graph and two nodes (src, dst). The
// function should return a boolean indicating whether or not there exists a
// directed path between the source and destination nodes.

// Complexity:
// Time: O(e) where e is the number of edges.
// Space: O(n) where n is the number of nodes.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// Iterative Depth-First Search (DFS) approach.
bool hasPath(
    const std::unordered_map<std::string, std::vector<std::string>> &graph,
    const std::string &src, const std::string &dst) {
  std::stack<std::string> stack;
  stack.push(src);

  while (!stack.empty()) {
    const auto current = stack.top();
    stack.pop();

    if (current == dst) {
      return true;
    }

    for (const auto &neighbor : graph.at(current)) {
      stack.push(neighbor);
    }
  }

  return false;
}

// Recursive Depth-First Search (DFS) approach.
bool hasPathRecursive(
    const std::unordered_map<std::string, std::vector<std::string>> &graph,
    const std::string &src, const std::string &dst) {
  if (src == dst) {
    return true;
  }

  if (std::any_of(graph.at(src).begin(), graph.at(src).end(),
                  [&dst, &graph](const auto &neighbor) {
                    return hasPathRecursive(graph, neighbor, dst);
                  })) {
    return true;
  }

  return false;
}

int main() {
  std::unordered_map<std::string, std::vector<std::string>> graph1{
      {"f", {"g", "i"}}, {"g", {"h"}}, {"h", {}},
      {"i", {"g", "k"}}, {"j", {"i"}}, {"k", {}}};

  assert(hasPath(graph1, "f", "k"));           // -> true
  assert(hasPath(graph1, "f", "j") == false);  // -> false
  assert(hasPath(graph1, "i", "h"));           // -> true

  std::unordered_map<std::string, std::vector<std::string>> graph2{
      {"v", {"x", "w"}}, {"w", {}}, {"x", {}}, {"y", {"z"}}, {"z", {}}};

  assert(hasPath(graph2, "v", "w"));  // -> true

  std::cout << "All tests passed!\n";
  return 0;
}
