#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int MX = 101;
const int NIL = -1;

struct Node {
  int parent, left, right;
};

vector<Node> tree(MX);
vector<int> depths(MX);
vector<int> heights(MX);

void setDepth(int id, int depth) {
  depths[id] = depth;
  if (tree[id].left != NIL) setDepth(tree[id].left, depth + 1);
  if (tree[id].right != NIL) setDepth(tree[id].right, depth + 1);
  return;
}

int setHeight(int id) {
  int h1 = 0, h2 = 0;
  if (tree[id].left != NIL) h1 = setHeight(tree[id].left) + 1;
  if (tree[id].right != NIL) h2 = setHeight(tree[id].right) + 1;
  return heights[id] = (h1 > h2 ? h1 : h2);
}

int getSibling(int id) {
  if (tree[id].parent == NIL) return NIL;
  int p = tree[id].parent;
  if (tree[p].left != id && tree[p].left != NIL) return tree[p].left;
  if (tree[p].right != id && tree[p].right != NIL) return tree[p].right;
  return NIL;
}

int getDegree(int id) {
  int deg = 0;
  if (tree[id].left != NIL) deg++;
  if (tree[id].right != NIL) deg++;
  return deg;
}

string getType(int id) {
  if (tree[id].parent == NIL) {
    return "root";
  } else if (tree[id].left == NIL && tree[id].right == NIL) {
    return "leaf";
  } else {
    return "internal node";
  }
}

void print(int id) {
  cout << "node " << id << ": ";
  cout << "parent = " << tree[id].parent << ", ";
  cout << "sibling = " << getSibling(id) << ", ";
  cout << "degree = " << getDegree(id) << ", ";
  cout << "depth = " << depths[id] << ", ";
  cout << "height = " << heights[id] << ", ";
  cout << getType(id) << endl;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) tree[i].parent = NIL;
  rep(i, n) {
    int id, left, right;
    cin >> id >> left >> right;
    tree[id].left = left;
    tree[id].right = right;
    if (left != NIL) tree[left].parent = id;
    if (right != NIL) tree[right].parent = id;
  }

  int root = 0;
  rep(i, n) if (tree[i].parent == NIL) root = i;

  setDepth(root, 0);
  setHeight(root);

  rep(i, n) print(i);

  return 0;
}
