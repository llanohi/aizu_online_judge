#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int n, A[20];

bool solve(int i, int m) {
  if (m == 0) return true;
  if (i >= n) return false;
  return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main() {
  cin >> n;
  rep(i, n) cin >> A[i];
  int q;
  cin >> q;
  int m[q];
  rep(i, q) cin >> m[i];
  rep(i, q) cout << (solve(0, m[i]) ? "yes" : "no") << endl;

  return 0;
}
