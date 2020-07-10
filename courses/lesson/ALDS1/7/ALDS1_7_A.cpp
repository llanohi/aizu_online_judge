#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int MX = 100005;
const int NIL = -1;

struct Node {
  int parent, left, right;
};

vector<Node> tree(MX);
vector<int> depths(MX);

void setDepth(int id, int depth) {
  depths[id] = depth;
  if (tree[id].right != NIL) setDepth(tree[id].right, depth);
  if (tree[id].left != NIL) setDepth(tree[id].left, depth + 1);
}

void print(int id) {
  cout << "node " << id << ": ";
  cout << "parent = " << tree[id].parent << ", ";
  cout << "depth = " << depths[id] << ", ";

  if (tree[id].parent == NIL) {
    cout << "root, ";
  } else if (tree[id].left == NIL) {
    cout << "leaf, ";
  } else {
    cout << "internal node, ";
  }

  cout << "[";
  int i = 0, c = tree[id].left;
  while (c != NIL) {
    cout << (i == 0 ? "" : ", ");
    cout << c;
    c = tree[c].right;
    i++;
  }

  cout << "]" << endl;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) tree[i].parent = tree[i].left = tree[i].right = NIL;
  rep(i, n) {
    int id, k;
    cin >> id >> k;
    rep(j, k) {
      int c, l;
      cin >> c;
      if (j == 0) {
        tree[id].left = c;
      } else {
        tree[l].right = c;
      }
      tree[c].parent = id;
      l = c;
    }
  }

  int root;
  rep(i, n) if (tree[i].parent == NIL) root = i;

  setDepth(root, 0);

  rep(i, n) print(i);

  return 0;
}
