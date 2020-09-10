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
  int N, W;
  cin >> N >> W;
  vi value(N), weight(N);
  rep(i, N) cin >> value[i] >> weight[i];

  int dp[N + 1][W + 1];
  rep(i, N + 1) dp[i][0] = 0;
  rep(i, W + 1) dp[0][i] = 0;
  rep(i, N) rep(w, W + 1) {
    if (w >= weight[i]) {
      dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]);
    } else {
      dp[i + 1][w] = dp[i][w];
    }
  }

  cout << dp[N][W] << endl;
  return 0;
}
