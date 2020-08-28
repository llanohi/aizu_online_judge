#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

Node *find(Node *nd, int key) {
  while (nd != NIL && key != nd->key) {
    nd = key < nd->key ? nd->left : nd->right;
  }
  return nd;
}

void insert(int key) {
  Node *x = root;
  Node *y = NIL;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = key;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    x = z->key < x->key ? x->left : x->right;
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void printInorder(Node *nd) {
  if (nd == NIL) return;
  printInorder(nd->left);
  cout << " " << nd->key;
  printInorder(nd->right);
}

void printPreorder(Node *nd) {
  if (nd == NIL) return;
  cout << " " << nd->key;
  printPreorder(nd->left);
  printPreorder(nd->right);
}

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    string s;
    int key;
    cin >> s;
    if (s == "insert") {
      cin >> key;
      insert(key);
    } else if (s == "find") {
      cin >> key;
      Node *res = find(root, key);
      cout << (res != NIL ? "yes" : "no") << endl;
    } else {
      printInorder(root);
      cout << endl;
      printPreorder(root);
      cout << endl;
    }
  }
  return 0;
}
