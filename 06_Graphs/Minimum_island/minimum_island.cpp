// Minimum Island
//
// Write a function, minimumIsland, that takes in a grid containing 'W's and
// 'L's. 'W' represents water and 'L' represents land. The function should
// return the size of the smallest island. An island is a vertically or
// horizontally connected region of land.
//
// You may assume that the grid contains at least one island.

// Complexity:
// Time: O(R * C), where R is the number of rows and C is the number of columns.
// Space: O(R * C) due to recursive calls in worst-case scenario (DFS stack
// depth).

#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

const std::vector<std::pair<int, int>> kDirections = {
    {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int explore(const std::vector<std::vector<char>>& grid,
            std::unordered_set<std::string>& visited, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() ||
      grid[row][col] == 'W') {
    return 0;
  }

  std::string key = std::to_string(row) + "," + std::to_string(col);
  if (visited.count(key)) {
    return 0;
  }

  visited.insert(key);

  int size = 1;
  for (const auto& [dr, dc] : kDirections) {
    size += explore(grid, visited, row + dr, col + dc);
  }

  return size;
}

int minimumIsland(const std::vector<std::vector<char>>& grid) {
  std::unordered_set<std::string> visited;
  int smallest = std::numeric_limits<int>::max();

  for (size_t row = 0; row < grid.size(); ++row) {
    for (size_t col = 0; col < grid[row].size(); ++col) {
      if (grid[row][col] == 'L' &&
          !visited.count(std::to_string(row) + "," + std::to_string(col))) {
        int islandSize = explore(grid, visited, row, col);
        smallest = std::min(smallest, islandSize);
      }
    }
  }

  return smallest;
}

int main() {
  std::vector<std::vector<char>> grid1 = {
      {'W', 'L', 'W', 'W', 'W'}, {'W', 'L', 'W', 'W', 'W'},
      {'W', 'W', 'W', 'L', 'W'}, {'W', 'W', 'L', 'L', 'W'},
      {'L', 'W', 'W', 'L', 'L'}, {'L', 'L', 'W', 'W', 'W'}};
  assert(minimumIsland(grid1) == 2);

  std::vector<std::vector<char>> grid2 = {{'L', 'W', 'W', 'L', 'W'},
                                          {'L', 'W', 'W', 'L', 'L'},
                                          {'W', 'L', 'W', 'L', 'W'},
                                          {'W', 'W', 'W', 'W', 'W'},
                                          {'W', 'W', 'L', 'L', 'L'}};
  assert(minimumIsland(grid2) == 1);

  std::vector<std::vector<char>> grid3 = {
      {'L', 'L', 'L'}, {'L', 'L', 'L'}, {'L', 'L', 'L'}};
  assert(minimumIsland(grid3) == 9);

  std::cout << "All tests passed!\n";
  return 0;
}
