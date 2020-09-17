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

const int N = 4;
const int N2 = 16;
const int LIMIT = 100;

struct Puzzle {
  int f[N2], space, MD;
};

static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'r', 'u', 'l', 'd'};
int limit;
int MDT[N2][N2];

Puzzle state;
int path[LIMIT];

int getAllMD(Puzzle pz) {
  int sum = 0;
  rep(i, N2) {
    if (pz.f[i] == N2) continue;
    sum += MDT[i][pz.f[i] - 1];
  }
  return sum;
}

bool dfs(int depth, int prev) {
  if (state.MD == 0) return true;
  if (depth + state.MD > limit) return false;

  int sx = state.space % N;
  int sy = state.space / N;
  Puzzle tmp;

  rep(i, 4) {
    int tx = sx + dx[i];
    int ty = sy + dy[i];
    if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
    if (max(prev, i) - min(prev, i) == 2) continue;
    tmp = state;

    state.MD -= MDT[tx + ty * N][state.f[tx + ty * N] - 1];
    state.MD += MDT[sx + sy * N][state.f[tx + ty * N] - 1];
    swap(state.f[sx + sy * N], state.f[tx + ty * N]);
    state.space = tx + ty * N;
    if (dfs(depth + 1, i)) {
      path[depth] = i;
      return true;
    }
    state = tmp;
  }

  return false;
}

string interative_deepening(Puzzle in) {
  in.MD = getAllMD(in);
  for (limit = in.MD; limit <= LIMIT; limit++) {
    state = in;
    if (dfs(0, -100)) {
      string ans = "";
      rep(i, limit) ans += dir[path[i]];
      return ans;
    }
  }

  return "unsolvable";
}

int main() {
  rep(i, N2) rep(j, N2) MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
  Puzzle in;
  rep(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }
  string ans = interative_deepening(in);
  cout << ans.size() << endl;
  return 0;
}
