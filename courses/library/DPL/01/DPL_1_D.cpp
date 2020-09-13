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
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  int length = 1;
  int dp[n];
  dp[0] = a[0];
  srep(i, 1, n) {
    if (dp[length - 1] < a[i]) {
      dp[length++] = a[i];
    } else {
      *lower_bound(dp, dp + length, a[i]) = a[i];
    }
  }

  cout << length << endl;
  return 0;
}
