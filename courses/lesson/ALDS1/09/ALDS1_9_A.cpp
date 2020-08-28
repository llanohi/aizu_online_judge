#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;

int parent(int i) {
  return i / 2;
}

int left(int i) {
  return i * 2;
}

int right(int i) {
  return i * 2 + 1;
}

int main() {
  int H;
  cin >> H;
  vector<int> tree(H + 1);
  srep(i, 1, H + 1) cin >> tree[i];
  srep(i, 1, H + 1) {
    cout << "node " << i << ": ";
    cout << "key = " << tree[i] << ", ";
    if (parent(i) >= 1) cout << "parent key = " << tree[parent(i)] << ", ";
    if (left(i) <= H) cout << "left key = " << tree[left(i)] << ", ";
    if (right(i) <= H) cout << "right key = " << tree[right(i)] << ", ";
    cout << endl;
  }
  return 0;
}
