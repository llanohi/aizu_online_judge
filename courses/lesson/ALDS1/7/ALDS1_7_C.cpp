#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int MX = 101;
const int NIL = -1;

struct Node {
  int parent, left, right;
};

vector<Node> tree(MX);

void printPreorder(int id) {
  if (id == NIL) return;
  cout << " " << id;
  printPreorder(tree[id].left);
  printPreorder(tree[id].right);
}

void printInorder(int id) {
  if (id == NIL) return;
  printInorder(tree[id].left);
  cout << " " << id;
  printInorder(tree[id].right);
}

void printPostorder(int id) {
  if (id == NIL) return;
  printPostorder(tree[id].left);
  printPostorder(tree[id].right);
  cout << " " << id;
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

  cout << "Preorder" << endl;
  printPreorder(root);
  cout << endl;
  cout << "Inorder" << endl;
  printInorder(root);
  cout << endl;
  cout << "Postorder" << endl;
  printPostorder(root);
  cout << endl;

  return 0;
}
