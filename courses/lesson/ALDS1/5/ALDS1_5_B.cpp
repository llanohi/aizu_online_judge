#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
const int INF = 1001001001;

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int nl = mid - left;
  int nr = right - mid;
  int L[nl + 1], R[nr + 1];
  rep(i, nl) L[i] = A[left + i];
  rep(i, nr) R[i] = A[mid + i];
  L[nl] = R[nr] = INF;

  int i = 0, j = 0;
  srep(k, left, right) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
}

void mergeSort(int A[], int left, int right) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  rep(i, n) cin >> A[i];

  mergeSort(A, 0, n);

  rep(i, n) cout << (i == 0 ? "" : " ") << A[i];
  cout << endl;
  cout << cnt << endl;

  return 0;
}
