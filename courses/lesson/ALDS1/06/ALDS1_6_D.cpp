#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rng(a) a.begin(), a.end()
#define mins(x, y) (x = min(x, y))
using namespace std;
typedef vector<int> vi;
const int VMAX = 10000;

int solve(vi w, int n) {
  vi s(n), checked(n);
  rep(i, n) {
    s[i] = w[i];
    checked[i] = false;
  }
  sort(rng(s));
  vi idx(VMAX + 1);
  rep(i, n) idx[s[i]] = i;
  int x = *min_element(rng(w));
  int ans = 0;
  rep(i, n) {
    if (checked[i]) continue;
    int cur = i;
    int total = 0;
    int mn = VMAX;
    int cnt = 0;
    while (!checked[cur]) {
      int v = w[cur];
      total += v;
      mins(mn, v);
      cnt++;
      checked[cur] = true;
      cur = idx[v];
    }
    ans += min(total + (cnt - 2) * mn, total + mn + (cnt + 1) * x);
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  vi w(n);
  rep(i, n) cin >> w[i];

  int ans = solve(w, n);

  cout << ans << endl;
  return 0;
}
