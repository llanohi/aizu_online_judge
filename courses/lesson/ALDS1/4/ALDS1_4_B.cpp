#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef vector<int> vi;

bool binarySearch(vi A, int key) {
  int left = -1;
  int right = A.size();
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (A[mid] == key) {
      return true;
    } else if (A[mid] < key) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return false;
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
