#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> R(n);
  rep(i, n) cin >> R[i];

  int ans = -1000000000;
  int min_p = R[0];

  rep(i, n - 1) {
    ans = max(ans, R[i + 1] - min_p);
    min_p = min(min_p, R[i + 1]);
  }

  cout << ans << endl;
  return 0;
}
