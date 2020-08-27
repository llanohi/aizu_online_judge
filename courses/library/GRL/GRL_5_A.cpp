#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

class Edge {
 public:
  int t, w;
  Edge() {
  }
  Edge(int t, int w) : t(t), w(w) {
  }
};

vector<Edge> g[MX];
int n, d[MX];
bool isVisited[MX];
int cnt;

void bfs(int s) {
  rep(i, n) d[i] = INF;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    rep(i, g[u].size()) {
      Edge e = g[u][i];
      if (d[e.t] == INF) {
        d[e.t] = d[u] + e.w;
        q.push(e.t);
      }
    }
  }
}

int solve() {
  bfs(0);
  int maxv = 0;
  int target = 0;
  rep(i, n) {
    if (d[i] == INF) continue;
    if (maxv < d[i]) {
      maxv = d[i];
      target = i;
    }
  }

  bfs(target);
  maxv = 0;
  rep(i, n) {
    if (d[i] == INF) continue;
    maxv = max(maxv, d[i]);
  }

  return maxv;
}

int main() {
  cin >> n;
  rep(i, n - 1) {
    int s, t, w;
    cin >> s >> t >> w;

    g[s].push_back(Edge(t, w));
    g[t].push_back(Edge(s, w));
  }

  int ans = solve();
  cout << ans << endl;

  return 0;
}
