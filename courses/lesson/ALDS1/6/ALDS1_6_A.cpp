#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const int MAXV = 10000;

void countingSort(int A[], int B[], int k, int n) {
  int C[k];
  rep(i, k) C[i] = 0;
  rep(i, n) C[A[i]]++;
  rep(i, k - 1) C[i + 1] += C[i];
  drep(i, n) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n], B[n];
  rep(i, n) cin >> A[i];

  countingSort(A, B, MAXV + 1, n);

  rep(i, n) cout << (i == 0 ? "" : " ") << B[i];
  cout << endl;

  return 0;
}
