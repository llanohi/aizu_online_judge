#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  vvi dp(m + 1, vi(n + 1));
  rep(i, m + 1) dp[i][0] = 0;
  rep(i, n + 1) dp[0][i] = 0;
  srep(i, 1, m + 1) srep(j, 1, n + 1) {
    if (X[i - 1] == Y[j - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    } else {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}
int main() {
  int q;
  cin >> q;
  rep(i, q) {
    string X, Y;
    cin >> X >> Y;

    cout << lcs(X, Y) << endl;
  }

  return 0;
}
