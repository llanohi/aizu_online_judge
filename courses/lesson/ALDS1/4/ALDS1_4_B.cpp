#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef vector<int> vi;

int solve(int val, int key) {
  return val <= key;
}

bool binarySearch(vi A, int key) {
  int ok = -1;
  int ng = A.size();
  while (abs(ng - ok) > 1) {
    int mid = (ng + ok) / 2;
    if (solve(A[mid], key)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return A[ok] == key;
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
    if (binarySearch(S, T[i])) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
