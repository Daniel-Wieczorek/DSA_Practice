// Undirected Path
//
// Write a function, undirectedPath, that takes in a vector of edges for an
// undirected graph and two nodes (nodeA, nodeB). The function should return a
// boolean indicating whether or not there exists a path between nodeA and
// nodeB.

// Complexity:
// Time: O(e + v) where e is the number of edges and v is the number of
// vertices. Space: O(e + v) due to adjacency list storage and recursive DFS
// calls.

#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
using graphT = std::unordered_map<T, std::vector<T>>;
using StringGraph = graphT<std::string>;

StringGraph makeGraph(
    const std::vector<std::tuple<std::string, std::string>>& edges) {
  StringGraph result{};
  for (const auto& entry : edges) {
    const auto first_edge = std::get<0>(entry);
    const auto second_edge = std::get<1>(entry);
    result[first_edge].push_back(second_edge);
    result[second_edge].push_back(first_edge);
  }
  return result;
}

bool undirectedPath(StringGraph& graph, const std::string& src,
                    const std::string& dst,
                    std::unordered_set<std::string>& visited) {
  if (src == dst) {
    return true;
  }

  if (visited.count(src)) {
    return false;
  }

  visited.insert(src);

  for (const auto& neighbor : graph[src]) {
    if (undirectedPath(graph, neighbor, dst, visited)) {
      return true;
    }
  }
  return false;
}

bool undirectedPath(
    const std::vector<std::tuple<std::string, std::string>>& edges,
    const std::string& src, const std::string& dst) {
  std::unordered_set<std::string> visited;
  StringGraph graph = makeGraph(edges);
  return undirectedPath(graph, src, dst, visited);
}

int main() {
  std::vector<std::tuple<std::string, std::string>> edges1{
      {"i", "j"}, {"k", "i"}, {"m", "k"}, {"k", "l"}, {"o", "n"}};

  assert(undirectedPath(edges1, "j", "m"));           // -> true
  assert(undirectedPath(edges1, "m", "j"));           // -> true
  assert(undirectedPath(edges1, "l", "j"));           // -> true
  assert(undirectedPath(edges1, "k", "o") == false);  // -> false
  assert(undirectedPath(edges1, "i", "o") == false);  // -> false

  std::vector<std::tuple<std::string, std::string>> edges2{
      {"b", "a"}, {"c", "a"}, {"b", "c"}, {"q", "r"},
      {"q", "s"}, {"q", "u"}, {"q", "t"}};

  assert(undirectedPath(edges2, "a", "b"));           // -> true
  assert(undirectedPath(edges2, "a", "c"));           // -> true
  assert(undirectedPath(edges2, "r", "t"));           // -> true
  assert(undirectedPath(edges2, "r", "b") == false);  // -> false

  std::cout << "All tests passed!\n";
  return 0;
}
