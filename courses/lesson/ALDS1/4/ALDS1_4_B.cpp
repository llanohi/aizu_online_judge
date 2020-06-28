#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef vector<int> vi;

int main() {
  int n;
  cin >> n;
  vi S(n);
  rep(i, n) cin >> S[i];
  int q;
  cin >> q;
  vi T(q);
  rep(i, q) cin >> T[i];

  int ans = 0;
  rep(i, q) {
    if (*lower_bound(S.begin(), S.end(), T[i]) == T[i]) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
