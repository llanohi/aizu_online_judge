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
  int H, W;
  scanf("%d %d", &H, &W);
  int C[H][W];
  rep(h, H) rep(w, W) scanf("%d", &C[h][w]);

  int maxWidth = 0;
  int dp[H][W];
  rep(h, H) rep(w, W) {
    dp[h][w] = (C[h][w] + 1) % 2;
    maxWidth = max(maxWidth, dp[h][w]);
  }
  srep(h, 1, H) srep(w, 1, W) {
    if (C[h][w] == 1) {
      dp[h][w] = 0;
    } else {
      dp[h][w] = min(dp[h - 1][w - 1], min(dp[h - 1][w], dp[h][w - 1])) + 1;
      maxWidth = max(maxWidth, dp[h][w]);
    }
  }

  printf("%d\n", maxWidth * maxWidth);
  return 0;
}
