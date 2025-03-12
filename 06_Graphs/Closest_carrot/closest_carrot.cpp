// Closest Carrot
//
// Write a function, closestCarrot, that takes in a grid, a starting row, and a
// starting column. In the grid, 'X's are walls, 'O's are open spaces, and 'C's
// are carrots. The function should return a number representing the length of
// the shortest path from the starting position to a carrot. You may move up,
// down, left, or right, but cannot pass through walls (X). If there is no
// possible path to a carrot, then return -1.

// Complexity:
// Time: O(n * m) where n is the number of rows and m is the number of columns.
// Space: O(n * m) for the visited array and queue.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

static const std::vector<std::tuple<int, int>> kMovablePos{
    {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

std::string hashTuple(const int row, const int col) {
  return std::to_string(row) + "," + std::to_string(col);
}

std::vector<std::tuple<int, int>> calculateNewPositions(const int current_row,
                                                        const int current_col,
                                                        const int max_rows,
                                                        const int max_col) {
  std::vector<std::tuple<int, int>> positions{};
  for (const auto& [r, c] : kMovablePos) {
    const int new_row = current_row + r;
    const int new_col = current_col + c;

    if (new_row >= 0 && new_col >= 0 && new_row < max_rows &&
        new_col < max_col) {
      positions.push_back(std::make_tuple(new_row, new_col));
    }
  }

  return positions;
}

int closestCarrot(const std::vector<std::vector<char>>& grid,
                  const int startRow, const int startCol) {
  const int num_of_rows = grid.size();
  const int num_of_col = grid.at(0).size();

  std::unordered_set<std::string> visisted{};

  // ROW, COL, MOVES
  std::queue<std::tuple<int, int, int>> queue;
  const int moves = 0;
  queue.push(std::make_tuple(startRow, startCol, moves));
  visisted.insert(hashTuple(startRow, startCol));

  while (!queue.empty()) {
    const auto [row, col, step] = queue.front();
    queue.pop();

    if (grid.at(row).at(col) == 'C') {
      return step;
    }

    const auto new_positions =
        calculateNewPositions(row, col, num_of_rows, num_of_col);
    for (const auto& [r, c] : new_positions) {
      const auto current = hashTuple(r, c);
      if (visisted.count(current) == 0) {
        visisted.insert(current);
        if (grid.at(r).at(c) != 'X') {
          queue.push(std::make_tuple(r, c, step + 1));
        }
      }
    }
  }
  return -1;
}

int main() {
  std::vector<std::vector<char>> grid1 = {
      {'O', 'O', 'O', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O'},
      {'O', 'X', 'X', 'O', 'O'}, {'O', 'X', 'C', 'O', 'O'},
      {'O', 'X', 'X', 'O', 'O'}, {'C', 'O', 'O', 'O', 'O'}};
  assert(closestCarrot(grid1, 1, 2) == 4);

  std::vector<std::vector<char>> grid2 = {
      {'O', 'O', 'O', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O'},
      {'O', 'X', 'X', 'O', 'O'}, {'O', 'X', 'C', 'O', 'O'},
      {'O', 'X', 'X', 'O', 'O'}, {'C', 'O', 'O', 'O', 'O'}};
  assert(closestCarrot(grid2, 0, 0) == 5);

  std::vector<std::vector<char>> grid3 = {
      {'O', 'O', 'X', 'X', 'X'}, {'O', 'X', 'X', 'X', 'C'},
      {'O', 'X', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'X', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'C', 'O', 'O'}, {'O', 'O', 'O', 'O', 'O'}};
  assert(closestCarrot(grid3, 3, 4) == 9);

  std::vector<std::vector<char>> grid4 = {
      {'O', 'O', 'X', 'O', 'O'},
      {'O', 'X', 'X', 'X', 'O'},
      {'O', 'X', 'C', 'C', 'O'},
  };
  assert(closestCarrot(grid4, 1, 4) == 2);
  assert(closestCarrot(grid4, 2, 0) == -1);

  std::vector<std::vector<char>> grid5 = {
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'C'},
  };
  assert(closestCarrot(grid5, 0, 0) == -1);

  std::cout << "All tests passed!\n";
  return 0;
}
