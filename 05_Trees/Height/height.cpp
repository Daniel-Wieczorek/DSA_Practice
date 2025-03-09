// How High (https://www.structy.net/)
//
// Write a function, howHigh, that takes in a pointer to the root of a binary
// tree. The function should return a number representing the height of the
// tree.
//
// The height of a binary tree is defined as the maximal number of edges from
// the root node to any leaf node.
//
// If the tree is empty, return -1.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the tree, as we must visit each
// node once. Space: O(h) where h is the height of the tree, as we may need to
// store up to h recursive calls.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

int howHigh(Node* root) {
  if (root == nullptr) {
    return -1;  // do not count null node edge
  }

  return 1 + std::max(howHigh(root->left), howHigh(root->right));
  // 1 is used here to indicate each child is one edge taller!
}

int main() {
  // Test case 1
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

  assert(howHigh(&a) == 2);  // -> 2

  std::cout << "All tests passed!\n";
  return 0;
}
