// Bottom Right Value (https://www.structy.net/)
//
// Write a function, bottomRightValue, that takes in a pointer to the root of a
// binary tree. The function should return the right-most value in the
// bottom-most level of the tree.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the tree.
// Space: O(n) where n is the number of nodes in the tree, due to the queue
// storing nodes at the current level.

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

std::string bottomRightValue(Node* root) {
  if (root == nullptr) {
    return "";
  }

  std::queue<Node*> queue{};
  queue.push(root);
  Node* current = nullptr;

  while (!queue.empty()) {
    current = queue.front();
    queue.pop();

    if (current->left != nullptr) {
      queue.push(current->left);
    }
    if (current->right != nullptr) {
      queue.push(current->right);
    }
  }

  return (current == nullptr ? "" : current->val);
}

int main() {
  Node a("3");
  Node b("11");
  Node c("10");
  Node d("4");
  Node e("-2");
  Node f("1");

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  // Test 1: Expected output "1"
  assert(bottomRightValue(&a) == "1");

  Node a1("-1");
  Node b1("-6");
  Node c1("-5");
  Node d1("-3");
  Node e1("-4");
  Node f1("-13");
  Node g1("-2");
  Node h1("6");

  a1.left = &b1;
  a1.right = &c1;
  b1.left = &d1;
  b1.right = &e1;
  c1.right = &f1;
  e1.left = &g1;
  e1.right = &h1;

  // Test 2: Expected output "6"
  assert(bottomRightValue(&a1) == "6");

  Node a2("-1");
  Node b2("-6");
  Node c2("-5");
  Node d2("-3");
  Node e2("-4");
  Node f2("-13");
  Node g2("-2");
  Node h2("6");
  Node i("7");

  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  c2.right = &f2;
  e2.left = &g2;
  e2.right = &h2;
  f2.left = &i;

  // Test 3: Expected output "7"
  assert(bottomRightValue(&a2) == "7");

  Node a3("a");
  Node b3("b");
  Node c3("c");
  Node d3("d");
  Node e3("e");
  Node f3("f");

  a3.left = &b3;
  a3.right = &c3;
  b3.right = &d3;
  d3.left = &e3;
  e3.right = &f3;

  // Test 4: Expected output "f"
  assert(bottomRightValue(&a3) == "f");

  std::cout << "All tests passed!\n";
  return 0;
}
