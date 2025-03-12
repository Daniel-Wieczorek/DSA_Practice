// Breadth-First Search (BFS)
//
// Implement BFS for a graph and print the data inside the graph.
//
// Complexity:
// Time: O(V + E), where V is the number of vertices and E is the number of
// edges. Space: O(V), as we store the vertices in the queue and visited set.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
using graphT = std::unordered_map<T, std::vector<T>>;

void bfs(const graphT<std::string> &graph, const std::string &start) {
  std::queue<std::string> queue;
  queue.push(start);

  std::vector<std::string> result;  // Store output for testing

  while (!queue.empty()) {
    const auto current = queue.front();
    queue.pop();
    result.push_back(current);

    for (const auto &neighbor : graph.at(current)) {
      queue.push(neighbor);
    }
  }

  // Print result
  for (const auto &node : result) {
    std::cout << node << " ";
  }
  std::cout << "\n";

  // Validation with expected output
  std::vector<std::string> expected{"a", "b", "c", "d", "e", "f"};
  assert(result == expected);
}

int main() {
  graphT<std::string> graph{{"a", {"b", "c"}}, {"b", {"d"}}, {"c", {"e"}},
                            {"d", {"f"}},      {"e", {}},    {"f", {}}};

  bfs(graph, "a");

  std::cout << "All tests passed!\n";
  return 0;
}
