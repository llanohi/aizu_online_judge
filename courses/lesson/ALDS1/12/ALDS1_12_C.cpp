#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> P;

const int MX = 10000;
const int INF = 1001001001;
int n;
vector<P> A[MX];

void dijkstra() {
  priority_queue<P> PQ;
  int d[n];
  bool isChecked[n];
  rep(i, n) {
    d[i] = INF;
    isChecked[i] = false;
  }
  d[0] = 0;

  PQ.push(make_pair(0, 0));

  while (!PQ.empty()) {
    P f = PQ.top();
    PQ.pop();
    int u = f.second;
    isChecked[u] = true;

    if (d[u] < f.first * (-1)) continue;

    rep(i, A[u].size()) {
      int v = A[u][i].first;
      if (isChecked[v]) continue;
      if (d[v] > d[u] + A[u][i].second) {
        d[v] = d[u] + A[u][i].second;
        PQ.push(make_pair(d[v] * (-1), v));
      }
    }
  }

  rep(i, n) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
}

int main() {
  int u, k, v, c;
  cin >> n;
  rep(i, n) {
    cin >> u >> k;
    rep(j, k) {
      cin >> v >> c;
      A[u].push_back(make_pair(v, c));
    }
  }

  dijkstra();

  return 0;
}
