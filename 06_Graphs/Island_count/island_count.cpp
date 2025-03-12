// Island Count
//
// Write a function, islandCount, that takes in a grid containing 'W's and 'L's.
// 'W' represents water, and 'L' represents land. The function should return the
// number of islands in the grid. An island is a vertically or horizontally
// connected region of land.

// Complexity:
// Time: O(n * m) where n is the number of rows and m is the number of columns.
// Space: O(n * m) due to the recursion depth in the worst case.

#include <cassert>
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
      grid[row][col] == 'W') {
    return;
  }

  grid[row][col] = 'W';  // Mark visited

  dfs(grid, row + 1, col);
  dfs(grid, row - 1, col);
  dfs(grid, row, col + 1);
  dfs(grid, row, col - 1);
}

int islandCount(std::vector<std::vector<char>> grid) {
  int count = 0;

  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[0].size(); ++col) {
      if (grid[row][col] == 'L') {
        ++count;
        dfs(grid, row, col);
      }
    }
  }

  return count;
}

int main() {
  std::vector<std::vector<char>> grid1{
      {'W', 'L', 'W', 'W', 'W'}, {'W', 'L', 'W', 'W', 'W'},
      {'W', 'W', 'W', 'L', 'W'}, {'W', 'W', 'L', 'L', 'W'},
      {'L', 'W', 'W', 'L', 'L'}, {'L', 'L', 'W', 'W', 'W'}};
  assert(islandCount(grid1) == 3);

  std::vector<std::vector<char>> grid2{{'L', 'W', 'W', 'L', 'W'},
                                       {'L', 'W', 'W', 'L', 'L'},
                                       {'W', 'L', 'W', 'L', 'W'},
                                       {'W', 'W', 'W', 'W', 'W'},
                                       {'W', 'W', 'L', 'L', 'L'}};
  assert(islandCount(grid2) == 4);

  std::vector<std::vector<char>> grid3{
      {'L', 'L', 'L'}, {'L', 'L', 'L'}, {'L', 'L', 'L'}};
  assert(islandCount(grid3) == 1);

  std::vector<std::vector<char>> grid4{
      {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}};
  assert(islandCount(grid4) == 0);

  std::cout << "All tests passed!\n";
  return 0;
}
