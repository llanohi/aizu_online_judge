#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n;
  cin >> n;
  vvi Adj(n, vi(n));
  rep(i, n) rep(j, n) Adj[i][j] = 0;
  rep(i, n) {
    int u, k, v;
    cin >> u >> k;
    rep(j, k) {
      cin >> v;
      Adj[i][v - 1] = 1;
    }
  }

  rep(i, n) {
    rep(j, n) {
      cout << (j == 0 ? "" : " ") << Adj[i][j];
    }
    cout << endl;
  }

  return 0;
}
