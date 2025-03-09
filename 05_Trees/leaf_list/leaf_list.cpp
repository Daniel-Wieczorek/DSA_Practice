// Leaf List
//
// Write a function, leafList, that takes in a pointer to the root of a binary
// tree and returns a vector containing the values of all leaf nodes in
// left-to-right order.

// Complexity:
// Time: O(n) where n is the number of nodes in the tree.
// Space: O(n) in the worst case (unbalanced tree).

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

std::vector<std::string> leafList(Node* root) {
  std::vector<std::string> output{};
  if (root == nullptr) {
    return output;
  }

  std::stack<Node*> stack{};
  stack.push(root);

  while (!stack.empty()) {
    Node* current = stack.top();
    stack.pop();

    if (current->left == nullptr && current->right == nullptr) {
      output.push_back(current->val);
    }

    if (current->right != nullptr) {
      stack.push(current->right);
    }
    if (current->left != nullptr) {
      stack.push(current->left);
    }
  }

  return output;
}

int main() {
  Node a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;
  assert((leafList(&a) == std::vector<std::string>{"d", "e", "f"}));

  Node g("g"), h("h");
  e.left = &g;
  f.right = &h;
  assert((leafList(&a) == std::vector<std::string>{"d", "g", "h"}));

  Node a2("5"), b2("11"), c2("54"), d2("20"), e2("15"), f2("1"), g2("3");
  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  e2.left = &f2;
  e2.right = &g2;
  assert((leafList(&a2) == std::vector<std::string>{"20", "1", "3", "54"}));

  Node x("x");
  assert((leafList(&x) == std::vector<std::string>{"x"}));

  std::cout << "All tests passed!\n";
  return 0;
}
