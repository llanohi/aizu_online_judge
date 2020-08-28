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

Node *treeMinimum(Node *nd) {
  while (nd->left != NIL) nd = nd->left;
  return nd;
}

// 中間順巡回で次に訪問される接点を返す
Node *treeSuccessor(Node *nd) {
  if (nd->right != NIL) return treeMinimum(nd->right);
  Node *x = nd->parent;
  while (x != NIL && nd == x->right) {
    nd = x;
    x = x->parent;
  }
  return x;
}

void treeDelete(Node *nd) {
  Node *x;  // 削除する節点
  Node *y;  // 削除する接点の子

  if (nd->left == NIL || nd->right == NIL) {
    x = nd;
  } else {
    x = treeSuccessor(nd);
  }

  // x の子である y を決める
  y = x->left != NIL ? x->left : x->right;

  // y の親を x の親に変える
  if (y != NIL) y->parent = x->parent;

  // x の親がもつ子 x を y に変える
  if (x->parent == NIL) {
    root = y;
  } else {
    if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
  }

  if (x != nd) nd->key = x->key;

  free(x);
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
    } else if (s == "delete") {
      cin >> key;
      treeDelete(find(root, key));
    } else {
      printInorder(root);
      cout << endl;
      printPreorder(root);
      cout << endl;
    }
  }
  return 0;
}
