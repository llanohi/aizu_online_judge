#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;

long long cnt;
vector<int> G;
int A[1000000];

void insertionSort(int A[], int n, int g) {
  srep(i, g, n) {
    int v = A[i];
    int j = i - g;

    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }

    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = 3 * h + 1;
  }

  drep(i, G.size()) insertionSort(A, n, G[i]);
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> A[i];

  cnt = 0;
  shellSort(A, n);

  cout << G.size() << endl;
  drep(i, G.size()) {
    cout << G[i];
    if (i != 0) {
      cout << " ";
    }
  }
  cout << endl;

  cout << cnt << endl;
  rep(i, n) {
    cout << A[i] << endl;
  }
  return 0;
}
