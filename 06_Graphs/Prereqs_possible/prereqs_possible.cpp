// Prereqs Possible
//
// Write a function, prereqsPossible, that takes in a number of courses (n) and
// prerequisites as arguments. Courses have ids ranging from 0 through n - 1.
// A single prerequisite of {A, B} means that course A must be taken before
// course B. The function should return a boolean indicating whether or not
// it is possible to complete all courses.

// Complexity:
// Time: O(n + m), where n is the number of courses and m is the number of
// prerequisite relationships.
// Space: O(n + m) due to adjacency list storage and recursion depth.

#include <cassert>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using GraphT = std::unordered_map<int, std::vector<int>>;

GraphT buildGraph(int numCourses,
                  const std::vector<std::tuple<int, int>>& prereqs) {
  GraphT graph;

  // Initialize all courses to avoid missing isolated nodes
  for (int i = 0; i < numCourses; i++) {
    graph[i] = {};
  }

  for (const auto& [nodeA, nodeB] : prereqs) {
    graph[nodeA].push_back(nodeB);
  }

  return graph;
}

bool hasCycle(const GraphT& graph, std::unordered_set<int>& visiting,
              std::unordered_set<int>& visited, int current) {
  if (visited.count(current)) return false;
  if (visiting.count(current)) return true;

  visiting.insert(current);

  for (const auto& neighbor : graph.at(current)) {
    if (hasCycle(graph, visiting, visited, neighbor)) {
      return true;
    }
  }

  visiting.erase(current);  // Remove only the current node
  visited.insert(current);  // Mark it as fully processed
  return false;
}

bool prereqsPossible(int numCourses,
                     const std::vector<std::tuple<int, int>>& prereqs) {
  std::unordered_set<int> visiting, visited;
  GraphT graph = buildGraph(numCourses, prereqs);

  for (const auto& [key, _] : graph) {
    if (!visited.count(key) && hasCycle(graph, visiting, visited, key)) {
      return false;
    }
  }

  return true;
}

int main() {
  int numCourses;
  std::vector<std::tuple<int, int>> prereqs;

  numCourses = 6;
  prereqs = {{0, 1}, {2, 3}, {0, 2}, {1, 3}, {4, 5}};
  assert(prereqsPossible(numCourses, prereqs) == true);

  numCourses = 6;
  prereqs = {{0, 1}, {2, 3}, {0, 2}, {1, 3}, {4, 5}, {3, 0}};
  assert(prereqsPossible(numCourses, prereqs) == false);

  numCourses = 5;
  prereqs = {{2, 4}, {1, 0}, {0, 2}, {0, 4}};
  assert(prereqsPossible(numCourses, prereqs) == true);

  numCourses = 6;
  prereqs = {{2, 4}, {1, 0}, {0, 2}, {0, 4}, {5, 3}, {3, 5}};
  assert(prereqsPossible(numCourses, prereqs) == false);

  numCourses = 8;
  prereqs = {{1, 0}, {0, 6}, {2, 0}, {0, 5}, {3, 7}, {4, 3}};
  assert(prereqsPossible(numCourses, prereqs) == true);

  numCourses = 8;
  prereqs = {{1, 0}, {0, 6}, {2, 0}, {0, 5}, {3, 7}, {7, 4}, {4, 3}};
  assert(prereqsPossible(numCourses, prereqs) == false);

  std::cout << "All tests passed!\n";
  return 0;
}
