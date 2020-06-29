#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n, k;
int W[100000];

bool isOk(ll P) {
  int i = 0;
  rep(j, k) {
    ll total = 0;
    while (total + W[i] <= P) {
      total += W[i];
      i++;
      if (i == n) return true;
    }
  }
  return false;
}

ll binarySearch() {
  ll ng = 0;
  ll ok = 100000 * 10000;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOk(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> W[i];
  ll ans = binarySearch();
  cout << ans << endl;
  return 0;
}
