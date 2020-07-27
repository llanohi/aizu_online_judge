#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 105;
const int INF = 1001001001;
vvi Adj(MX, vi(MX));
vi k(MX), d(MX);
int n, t = 0;

void bfs(int id) {
  queue<int> q;
  rep(i, n) d[i] = INF;
  d[id] = 0;
  q.push(id);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    rep(v, n) {
      if (Adj[x][v] == 0) continue;
      if (d[v] != INF) continue;
      d[v] = d[x] + 1;
      q.push(v);
    }
  }
}

int main() {
  cin >> n;
  rep(i, n) {
    rep(j, n) Adj[i][j] = 0;
  }
  rep(i, n) {
    int u, v;
    cin >> u >> k[i];
    u--;
    rep(j, k[i]) {
      cin >> v;
      Adj[u][v - 1] = 1;
    }
  }
  bfs(0);
  rep(i, n) {
    cout << i + 1 << " " << (d[i] == INF ? -1 : d[i]) << endl;
  }

  return 0;
}
