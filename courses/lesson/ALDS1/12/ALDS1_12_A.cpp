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

int prim() {
  vi d(n), p(n);
  vector<bool> isChecked(n);
  rep(i, n) {
    d[i] = INF;
    isChecked[i] = false;
  }
  d[0] = 0;
  p[0] = -1;

  int u;
  while (true) {
    int mincost = INF;
    rep(i, n) {
      if (!isChecked[i] && d[i] < mincost) {
        mincost = d[i];
        u = i;
      }
    }

    if (mincost == INF) break;

    isChecked[u] = true;

    rep(i, n) {
      if (!isChecked[i] && A[u][i] != INF) {
        if (A[u][i] < d[i]) {
          d[i] = A[u][i];
          p[i] = u;
        }
      }
    }
  }

  int total = 0;
  rep(i, n) if (p[i] != -1) total += A[i][p[i]];

  return total;
}

int main() {
  cin >> n;
  rep(i, n) rep(j, n) {
    int a;
    cin >> a;
    A[i][j] = (a == -1 ? INF : a);
  }

  cout << prim() << endl;

  return 0;
}
