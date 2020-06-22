#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

const int LEN = 1000002;

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;

void init() {
  nil = new Node();
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key) {
  Node *x = new Node();
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil) {
    if (cur->key == key) {
      break;
    }
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *x) {
  if (x == nil) {
    return;
  }
  x->prev->next = x->next;
  x->next->prev = x->prev;
}

void deleteKey(int key) {
  deleteNode(listSearch(key));
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void printList() {
  Node *cur = nil->next;
  int i = 0;
  while (cur != nil) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", cur->key);
    cur = cur->next;
    i++;
  }
  printf("\n");
}

int main() {
  int n;
  cin >> n;

  init();

  char cmd[20];
  int key;
  rep(i, n) {
    scanf("%s%d", cmd, &key);
    if (cmd[0] == 'i') {
      insert(key);
    } else if (cmd[0] == 'd') {
      if (strlen(cmd) > 6) {
        if (cmd[6] == 'F') {
          deleteFirst();
        } else {
          deleteLast();
        }
      } else {
        deleteKey(key);
      }
    }
  }

  printList();

  return 0;
}
