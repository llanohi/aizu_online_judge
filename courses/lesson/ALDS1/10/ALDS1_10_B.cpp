#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1001001001;

const int MX = 100;

int main() {
  int n;
  cin >> n;
  vi p(n + 1);
  rep(i, n) cin >> p[i] >> p[i + 1];

  vvi dp(n + 1, vi(n + 1));
  rep(i, n + 1) dp[i][i] = 0;
  srep(d, 1, n) srep(i, 1, n + 1 - d) {
    int j = i + d;
    dp[i][j] = INF;
    srep(k, i, j) {
      int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
      dp[i][j] = min(dp[i][j], cost);
    }
  }

  cout << dp[1][n] << endl;

  return 0;
}
