// Tree Levels
//
// Write a function, treeLevels, that takes in a pointer to the root of a binary
// tree. The function should return a 2-Dimensional vector where each subvector
// represents a level of the tree.

// Complexity:
// Time: O(n) where n is the number of nodes in the tree, as we traverse each
// node once. Space: O(n) due to storing the level-order traversal results and
// queue usage.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using Tpaths = std::vector<std::vector<std::string>>;

class Node {
 public:
  std::string val;
  Node *left;
  Node *right;

  explicit Node(const std::string &initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

Tpaths treeLevels(Node *root) {
  if (root == nullptr) {
    return {};
  }

  Tpaths result;
  std::queue<std::tuple<Node *, int>> queue;
  queue.push(std::make_tuple(root, 0));

  while (!queue.empty()) {
    auto [current, level] = queue.front();
    queue.pop();

    if (result.size() == level) {
      result.push_back({current->val});
    } else {
      result[level].push_back(current->val);
    }

    if (current->left) {
      queue.push(std::make_tuple(current->left, level + 1));
    }
    if (current->right) {
      queue.push(std::make_tuple(current->right, level + 1));
    }
  }

  return result;
}

void testTreeLevels() {
  // Test case 1
  Node a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;
  assert(treeLevels(&a) == Tpaths({{"a"}, {"b", "c"}, {"d", "e", "f"}}));

  // Test case 2
  Node g("g"), h("h"), i("i");
  e.left = &g;
  e.right = &h;
  f.left = &i;
  assert(treeLevels(&a) ==
         Tpaths({{"a"}, {"b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}}));

  // Test case 3
  Node q("q"), r("r"), s("s"), t("t"), u("u"), v("v");
  q.left = &r;
  q.right = &s;
  r.right = &t;
  t.left = &u;
  u.right = &v;
  assert(treeLevels(&q) == Tpaths({{"q"}, {"r", "s"}, {"t"}, {"u"}, {"v"}}));

  std::cout << "All tests passed!\n";
}

int main() {
  testTreeLevels();
  return 0;
}
