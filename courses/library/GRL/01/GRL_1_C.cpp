#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

int n;
ll dp[MX][MX];

void warshallFloyd() {
  rep(k, n) rep(i, n) {
    if (dp[i][k] == LINF) continue;
    rep(j, n) {
      if (dp[k][j] == LINF) continue;
      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
  }
}

int main() {
  int e;
  cin >> n >> e;
  rep(i, n) rep(j, n) dp[i][j] = ((i == j) ? 0 : LINF);
  rep(i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    dp[s][t] = d;
  }

  warshallFloyd();

  rep(i, n) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  rep(i, n) {
    rep(j, n) {
      cout << (j == 0 ? "" : " ");
      if (dp[i][j] == LINF) {
        cout << "INF";
      } else {
        cout << dp[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
