// Tree Min Value (https://www.structy.net/)
//
// Write a function, treeMinValue, that takes in a pointer to the root of a
// binary tree that contains number values. The function should return the
// minimum value within the tree.
//
// You may assume that the input tree is non-empty.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the tree, as each node is
// visited once. Space: O(n) due to the space used by the queue to store nodes
// during traversal.

#include <cassert>
#include <iostream>
#include <queue>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  explicit Node(const int initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

int treeMinValue(Node* root) {
  if (root == nullptr) {
    return 0;  // Assuming the tree will never be empty, but this handles edge
               // cases.
  }

  int min_val = root->val;
  std::queue<Node*> queue{};
  queue.push(root);

  while (!queue.empty()) {
    const auto current = queue.front();
    if (current->val < min_val) {
      min_val = current->val;
    }

    queue.pop();

    if (current->left != nullptr) {
      queue.push(current->left);
    }
    if (current->right != nullptr) {
      queue.push(current->right);
    }
  }

  return min_val;
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

  //       3
  //    /    \
    //   11     4
  //  / \      \
    // 4   -2     1
  assert(treeMinValue(&a) == -2);  // -> -2

  Node a2(5);
  Node b2(11);
  Node c2(3);
  Node d2(4);
  Node e2(14);
  Node f2(12);

  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  c2.right = &f2;

  //       5
  //    /    \
    //   11     3
  //  / \      \
    // 4   14     12
  assert(treeMinValue(&a2) == 3);  // -> 3

  Node a3(-1);
  Node b3(-6);
  Node c3(-5);
  Node d3(-3);
  Node e3(-4);
  Node f3(-13);
  Node g3(-2);
  Node h3(-2);

  a3.left = &b3;
  a3.right = &c3;
  b3.left = &d3;
  b3.right = &e3;
  c3.right = &f3;
  e3.left = &g3;
  f3.right = &h3;

  //        -1
  //      /   \
    //    -6    -5
  //   /  \     \
    // -3   -4   -13
  //     /       \
    //    -2       -2
  assert(treeMinValue(&a3) == -13);  // -> -13

  std::cout << "All tests passed!\n";
  return 0;
}
