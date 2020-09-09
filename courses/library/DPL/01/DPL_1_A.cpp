#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

int main() {
  int n, m;
  cin >> n >> m;
  vi c(n);
  rep(i, m) cin >> c[i];
  vi dp(n + 1, INF);
  dp[0] = 0;
  rep(i, m) rep(j, n - c[i] + 1) {
    dp[c[i] + j] = min(dp[c[i] + j], dp[j] + 1);
  }

  cout << dp[n] << endl;
  return 0;
}
