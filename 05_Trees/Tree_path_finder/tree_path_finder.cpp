// Tree Path Finder (https://www.structy.net/)
//
// Write a function, pathFinder, that takes in a pointer to the root of a binary
// tree and a target value. The function should return a pointer to a vector
// representing a path to the target value.
//
// If the target value is not present in the tree, then return nullptr;
//
// You may assume that the tree contains unique values.
//
// Complexity:
// Time: O(n^2) where n is the number of nodes, as each vector insertion takes
// linear time. Space: O(n) due to the space used for the recursive call stack
// and the dynamically allocated vector.

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using strVecPtr = std::vector<std::string>*;

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

strVecPtr pathFinder(Node* root, const std::string& targetVal) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == targetVal) {
    return new std::vector<std::string>({root->val});
  }

  strVecPtr left = pathFinder(root->left, targetVal);
  if (left != nullptr) {
    left->insert(left->begin(), root->val);
    return left;
  }

  strVecPtr right = pathFinder(root->right, targetVal);
  if (right != nullptr) {
    right->insert(right->begin(), root->val);
    return right;
  }

  return nullptr;
}

void testPathFinder() {
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");
  Node e("e");
  Node f("f");

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  // Test case 1: Path to "e"
  strVecPtr result = pathFinder(&a, "e");
  assert(result != nullptr);
  assert(result->size() == 3);
  assert((*result)[0] == "a");
  assert((*result)[1] == "b");
  assert((*result)[2] == "e");

  // Test case 2: Target "p" is not in the tree
  result = pathFinder(&a, "p");
  assert(result == nullptr);

  // Test case 3: Path to "c"
  result = pathFinder(&a, "c");
  assert(result != nullptr);
  assert(result->size() == 2);
  assert((*result)[0] == "a");
  assert((*result)[1] == "c");

  // Test case 4: Path to "h"
  Node g("g");
  Node h("h");
  e.left = &g;
  f.right = &h;

  result = pathFinder(&a, "h");
  assert(result != nullptr);
  assert(result->size() == 4);
  assert((*result)[0] == "a");
  assert((*result)[1] == "c");
  assert((*result)[2] == "f");
  assert((*result)[3] == "h");

  // Test case 5: Path to "x" in a single node tree
  Node x("x");
  result = pathFinder(&x, "x");
  assert(result != nullptr);
  assert(result->size() == 1);
  assert((*result)[0] == "x");

  // Test case 6: Null tree
  result = pathFinder(nullptr, "x");
  assert(result == nullptr);
}

int main() {
  testPathFinder();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}
