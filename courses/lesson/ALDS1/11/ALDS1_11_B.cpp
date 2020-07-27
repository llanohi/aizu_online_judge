#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 105;
vvi Adj(MX, vi(MX));
vi k(MX), d(MX), f(MX);
int n, t = 0;

void dfs(int id) {
  if (d[id - 1] != 0) return;
  d[id - 1] = ++t;
  rep(i, n) if (Adj[id - 1][i] == 1) dfs(i + 1);
  f[id - 1] = ++t;
}

int main() {
  cin >> n;
  rep(i, n) {
    rep(j, n) Adj[i][j] = 0;
    d[i] = f[i] = 0;
  }
  rep(i, n) {
    int u, v;
    cin >> u >> k[i];
    rep(j, k[i]) {
      cin >> v;
      Adj[i][v - 1] = 1;
    }
  }

  rep(i, n) dfs(i + 1);
  rep(i, n) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }

  return 0;
}
