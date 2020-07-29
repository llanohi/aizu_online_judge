#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100;
const int INF = 1001001001;
int n;
vvi A(MX, vi(MX));

void dijkstra() {
  vi d(n);
  vector<bool> isChecked(n);
  rep(i, n) {
    d[i] = INF;
    isChecked[i] = false;
  }
  d[0] = 0;

  int u;
  while (true) {
    int minv = INF;
    rep(i, n) {
      if (!isChecked[i] && d[i] < minv) {
        minv = d[i];
        u = i;
      }
    }

    if (minv == INF) break;

    isChecked[u] = true;

    rep(i, n) {
      if (!isChecked[i] && A[u][i] != INF) {
        if (d[i] > d[u] + A[u][i]) {
          d[i] = d[u] + A[u][i];
        }
      }
    }
  }

  rep(i, n) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
}

int main() {
  cin >> n;
  rep(i, n) rep(j, n) A[i][j] = INF;
  rep(i, n) {
    int u, k, v, c;
    cin >> u >> k;
    rep(j, k) {
      cin >> v >> c;
      A[u][v] = c;
    }
  }

  dijkstra();

  return 0;
}
