// Tree Includes (https://www.structy.net/)
//
// Write a function, treeIncludes, that takes in a pointer to the root of a
// binary tree and a target value. The function should return a boolean
// indicating whether or not the value is contained in the tree.

// Complexity:
// Time: O(n) where n is the number of nodes in the tree. Each node is visited
// once. Space: O(n) in the worst case (if the tree is completely unbalanced).
// In a balanced tree, the space complexity would be O(log n) due to queue
// usage.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

bool treeIncludes(Node* root, const std::string& targetVal) {
  if (root == nullptr) {
    return false;
  }

  std::queue<Node*> queue{};
  queue.push(root);

  while (!queue.empty()) {
    Node* current = queue.front();
    queue.pop();

    if (current->val == targetVal) {
      return true;
    }

    if (current->left != nullptr) {
      queue.push(current->left);
    }

    if (current->right != nullptr) {
      queue.push(current->right);
    }
  }

  return false;
}

int main() {
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");
  Node e("e");
  Node f("f");
  Node g("g");
  Node h("h");

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;
  e.left = &g;
  f.right = &h;

  //      a
  //    /   \
  //   b     c
  //  / \     \
  // d   e     f
  //    /       \
  //   g         h

  assert(treeIncludes(&a, "e"));           // -> true
  assert(treeIncludes(&a, "a"));           // -> true
  assert(treeIncludes(&a, "n") == false);  // -> false
  assert(treeIncludes(&a, "f"));           // -> true
  assert(treeIncludes(&a, "p") == false);  // -> false

  std::cout << "All tests passed!\n";
  return 0;
}
