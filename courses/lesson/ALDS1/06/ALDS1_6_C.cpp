#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
const int INF = 1001001001;

struct Card {
  char suit;
  int value;
};

void merge(Card A[], int left, int mid, int right) {
  int nl = mid - left;
  int nr = right - mid;
  Card L[nl + 1], R[nr + 1];
  rep(i, nl) L[i] = A[left + i];
  rep(i, nr) R[i] = A[mid + i];
  L[nl].value = R[nr].value = INF;

  int i = 0, j = 0;
  srep(k, left, right) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r) {
  int x = A[r].value;
  int i = p - 1;

  srep(j, p, r) {
    if (A[j].value <= x) {
      i++;
      swap(A[j], A[i]);
    }
  }
  swap(A[i + 1], A[r]);

  return i + 1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

bool isStable(Card A[], Card B[], int n) {
  rep(i, n) {
    if (A[i].suit != B[i].suit) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  Card A[n], B[n];
  rep(i, n) cin >> A[i].suit >> A[i].value;
  rep(i, n) B[i] = A[i];

  mergeSort(A, 0, n);
  quickSort(B, 0, n - 1);

  cout << (isStable(A, B, n) ? "Stable" : "Not stable") << endl;
  rep(i, n) cout << B[i].suit << " " << B[i].value << endl;

  return 0;
}
