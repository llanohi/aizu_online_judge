#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;

int H, A[1001001];

int parent(int i) {
  return i / 2;
}

int left(int i) {
  return i * 2;
}

int right(int i) {
  return i * 2 + 1;
}

void maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l <= H && A[l] > A[largest]) largest = l;
  if (r <= H && A[r] > A[largest]) largest = r;
  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

int main() {
  cin >> H;
  srep(i, 1, H + 1) cin >> A[i];
  for (int i = H / 2; i >= 1; i--) maxHeapify(i);
  srep(i, 1, H + 1) cout << " " << A[i];
  cout << endl;
  return 0;
}
