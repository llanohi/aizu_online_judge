#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = dp[1] = 1;
  rep(i, n - 1) dp[i + 2] = dp[i] + dp[i + 1];

  cout << dp[n] << endl;

  return 0;
}
