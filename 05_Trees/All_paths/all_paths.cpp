// All Tree Paths
//
// Write a function, allTreePaths, that takes in a pointer to the root of a
// binary tree. The function should return a 2-Dimensional vector where each
// subvector represents a root-to-leaf path in the tree.
//
// The order within an individual path must start at the root and end at the
// leaf, but the relative order among paths in the outer vector does not matter.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the tree.
// Space: O(n) due to recursive call stack in the worst case (skewed tree).

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using Tpath = std::vector<std::vector<std::string>>;

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val(initialVal), left(nullptr), right(nullptr) {}
};

Tpath _allTreePaths(Node* root) {
  if (!root) return {};

  // If it's a leaf node, return a single path containing only this node
  if (!root->left && !root->right) return {{root->val}};

  Tpath result;

  Tpath leftPaths = _allTreePaths(root->left);
  for (auto& path : leftPaths) {
    path.push_back(root->val);
    result.push_back(path);
  }

  Tpath rightPaths = _allTreePaths(root->right);
  for (auto& path : rightPaths) {
    path.push_back(root->val);
    result.push_back(path);
  }

  return result;
}

Tpath allTreePaths(Node* root) {
  Tpath result;
  for (std::vector<std::string> path : _allTreePaths(root)) {
    std::reverse(path.begin(), path.end());
    result.push_back(path);
  }
  return result;
}

int main() {
  // Test case 1
  Node a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  Tpath expected1 = {{"a", "b", "d"}, {"a", "b", "e"}, {"a", "c", "f"}};
  assert(allTreePaths(&a) == expected1);

  // Test case 2
  Node g("g"), h("h"), i("i");
  e.left = &g;
  e.right = &h;
  f.left = &i;

  Tpath expected2 = {{"a", "b", "d"},
                     {"a", "b", "e", "g"},
                     {"a", "b", "e", "h"},
                     {"a", "c", "f", "i"}};
  assert(allTreePaths(&a) == expected2);

  // Test case 3
  Node q("q"), r("r"), s("s"), t("t"), u("u"), v("v");
  q.left = &r;
  q.right = &s;
  r.right = &t;
  t.left = &u;
  u.right = &v;

  Tpath expected3 = {{"q", "r", "t", "u", "v"}, {"q", "s"}};
  assert(allTreePaths(&q) == expected3);

  std::cout << "All tests passed!\n";
  return 0;
}
