#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef vector<int> vi;

int linearSearch(vi A, int n, int key) {
  int i = 0;
  A.push_back(key);
  while (A[i] != key) {
    i++;
  }
  return i != n;
}

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
    if (linearSearch(S, n, T[i])) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
