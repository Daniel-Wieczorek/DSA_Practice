// Max Root to Leaf Path Sum (https://www.structy.net/)
//
// Write a function, maxPathSum, that takes in a pointer to the root of a binary
// tree that contains number values. The function should return the maximum sum
// of any root to leaf path within the tree.
//
// You may assume that the input tree is non-empty.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the tree, as we visit each node
// once. Space: O(h) where h is the height of the tree due to recursion stack,
// in the worst case O(n).

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  explicit Node(const int initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

int maxPathSum(Node* root) {
  // empty tree use case
  if (root == nullptr) {
    return std::numeric_limits<int>::min();
  }

  // root node use case
  if (root->left == nullptr && root->right == nullptr) {
    return root->val;
  }

  // call it recursively
  int left_node = maxPathSum(root->left);
  int right_node = maxPathSum(root->right);
  if (left_node > right_node) {
    return root->val + left_node;
  } else {
    return root->val + right_node;
  }
}

int main() {
  Node a(3);
  Node b(11);
  Node c(4);
  Node d(4);
  Node e(-2);
  Node f(1);

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  // Test case 1
  assert(maxPathSum(&a) == 18);  // -> 18

  Node a2(5);
  Node b2(11);
  Node c2(54);
  Node d2(20);
  Node e2(15);
  Node f2(1);
  Node g2(3);

  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  e2.left = &f2;
  e2.right = &g2;

  // Test case 2
  assert(maxPathSum(&a2) == 59);  // -> 59

  Node a3(-1);
  Node b3(-6);
  Node c3(-5);
  Node d3(-3);
  Node e3(0);
  Node f3(-13);
  Node g3(-1);
  Node h3(-2);

  a3.left = &b3;
  a3.right = &c3;
  b3.left = &d3;
  b3.right = &e3;
  c3.right = &f3;
  e3.left = &g3;
  f3.right = &h3;

  // Test case 3
  assert(maxPathSum(&a3) == -8);  // -> -8

  std::cout << "All tests passed!\n";
  return 0;
}
