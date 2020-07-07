#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 1001001001;

ll merge(vi& A, int left, int mid, int right) {
  int l = mid - left;
  int r = right - mid;
  vi L(l + 1), R(r + 1);
  rep(i, l) L[i] = A[left + i];
  rep(i, r) R[i] = A[mid + i];
  L[l] = R[r] = INF;

  ll cnt = 0;
  int i = 0, j = 0;
  srep(k, left, right) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      cnt += l - i;
      j++;
    }
  }
  return cnt;
}

ll mergeSort(vi& A, int left, int right) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    ll c1 = mergeSort(A, left, mid);
    ll c2 = mergeSort(A, mid, right);
    ll c3 = merge(A, left, mid, right);
    return c1 + c2 + c3;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vi A(n);
  rep(i, n) cin >> A[i];

  ll ans = mergeSort(A, 0, n);

  cout << ans << endl;
  return 0;
}
