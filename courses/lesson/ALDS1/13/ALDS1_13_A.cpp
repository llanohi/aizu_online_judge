#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

const int N = 8;
const int FREE = -1;
const int NOT_FREE = -2;

bool X[N][N];
int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

void initialize() {
  rep(i, N) {
    row[i] = FREE;
    col[i] = FREE;
    // rep(j, N) X[i][j] = false;
  }
  rep(i, 2 * N - 1) {
    dpos[i] = FREE;
    dneg[i] = FREE;
  }
}

void printBoard() {
  rep(i, N) rep(j, N) if (X[i][j] && row[i] != j) return;
  rep(i, N) {
    rep(j, N) {
      cout << (row[i] == j ? "Q" : ".");
    }
    cout << endl;
  }
}

void backtracking(int i) {
  if (i == N) {
    printBoard();
    return;
  }

  rep(j, N) {
    if (col[j] == NOT_FREE || dpos[i + j] == NOT_FREE ||
        dneg[i - j + N - 1] == NOT_FREE) {
      continue;
    }
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    backtracking(i + 1);
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }
  return;
}

int main() {
  initialize();
  int k;
  cin >> k;
  rep(i, k) {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  backtracking(0);

  return 0;
}
