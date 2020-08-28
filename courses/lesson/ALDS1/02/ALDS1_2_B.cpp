#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;

void printList(vector<int> A, int n) {
  rep(i, n) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
}

void selectionSort(vector<int> A, int n) {
  int count = 0;

  rep(i, n - 1) {
    int min_j = i;

    srep(j, i, n) {
      if (A[j] < A[min_j]) {
        min_j = j;
      }
    }

    if (i != min_j) {
      swap(A[i], A[min_j]);
      count++;
    }
  }

  printList(A, n);
  cout << count << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  selectionSort(A, n);

  return 0;
}
