#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;

  srep(j, p, r) {
    if (A[j] <= x) {
      i++;
      swap(A[j], A[i]);
    }
  }
  swap(A[i + 1], A[r]);

  return i + 1;
}

int main() {
  int n;
  cin >> n;
  int A[n];
  rep(i, n) cin >> A[i];
  int p = 0, r = n - 1;

  int q = partition(A, p, r);
  rep(i, n) {
    if (i > 0) cout << " ";
    if (i == q) cout << "[";
    cout << A[i];
    if (i == q) cout << "]";
  }
  cout << endl;

  return 0;
}
