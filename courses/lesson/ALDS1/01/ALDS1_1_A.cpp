#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

void insertionSort(vector<int> A, int n) {
  rep(i, n - 1) {
    int tmp = A[i + 1];
    int j = i;

    while (j >= 0 && A[j] > tmp) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = tmp;

    printList(A, n);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  printList(A, n);
  insertionSort(A, n);

  return 0;
}
