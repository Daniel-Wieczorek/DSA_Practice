// Depth First Search (DFS)
//
// Implement a depth-first search (DFS) traversal for a graph. The function
// should print the data inside the graph in DFS order.
//
// Complexity:
// Time: O(V + E), where V is the number of vertices and E is the number of
// edges. Space: O(V), due to the stack storing at most all vertices in the
// worst case.

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
using graphT = std::unordered_map<T, std::vector<T>>;

std::vector<std::string> dfs(graphT<std::string> &graph,
                             const std::string &start) {
  std::stack<std::string> stack{};
  std::vector<std::string> result{};

  stack.push(start);

  while (!stack.empty()) {
    const std::string current = stack.top();
    stack.pop();
    result.push_back(current);

    for (const auto &neighbour : graph[current]) {
      stack.push(neighbour);
    }
  }
  return result;
}

int main() {
  graphT<std::string> graph{{"a", {"b", "c"}}, {"b", {"d"}}, {"c", {"e"}},
                            {"d", {"f"}},      {"e", {}},    {"f", {}}};

  std::vector<std::string> result = dfs(graph, "a");

  // Expected DFS traversal order (depends on stack order)
  std::vector<std::string> expected1 = {"a", "c", "e", "b", "d", "f"};
  std::vector<std::string> expected2 = {"a", "b", "d", "f", "c", "e"};

  assert(result == expected1 || result == expected2);

  std::cout << "All tests passed!\n";
  return 0;
}
