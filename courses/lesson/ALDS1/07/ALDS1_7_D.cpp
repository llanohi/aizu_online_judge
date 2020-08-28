#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int MX = 101;

int n, pos = 0;
vector<int> preorder(MX), inorder(MX), postorder;

void reconstruction(int l, int r) {
  if (l >= r) return;
  int root = preorder[pos];
  pos++;
  int m = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root));
  reconstruction(l, m);
  reconstruction(m + 1, r);
  postorder.push_back(root);
}

int main() {
  cin >> n;
  rep(i, n) cin >> preorder[i];
  rep(i, n) cin >> inorder[i];

  reconstruction(0, n);

  rep(i, n) cout << (i == 0 ? "" : " ") << postorder[i];
  cout << endl;

  return 0;
}
