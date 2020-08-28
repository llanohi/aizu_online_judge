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

void bubbleSort(vector<int> A, int n) {
  int count = 0;

  rep(i, n - 1) rep(j, n - 1 - i) {
    if (A[j] > A[j + 1]) {
      swap(A[j], A[j + 1]);
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

  bubbleSort(A, n);

  return 0;
}
