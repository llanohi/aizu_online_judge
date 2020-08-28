#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

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

int extractMax() {
  if (H < 1) return -INF;
  int maxv = A[1];
  A[1] = A[H--];
  maxHeapify(1);
  return maxv;
}

void increaseKey(int i, int key) {
  A[i] = key;
  while (i > 1 && A[parent(i)] < A[i]) {
    swap(A[i], A[parent(i)]);
    i /= 2;
  }
}

void insert(int key) {
  H++;
  increaseKey(H, key);
}

int main() {
  int key;
  string cmd;
  while (true) {
    cin >> cmd;
    if (cmd == "insert") {
      cin >> key;
      insert(key);
    } else if (cmd == "extract") {
      cout << extractMax() << endl;
    } else {
      break;
    }
  }

  return 0;
}
