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

const int N = 3;
const int N2 = 9;

struct Puzzle {
  int f[N2];
  int space;
  string path;

  bool operator<(const Puzzle &p) const {
    rep(i, N2) {
      if (f[i] == p.f[i]) continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};

static const int dx[4] = {0, 0, 1, -1};
static const int dy[4] = {1, -1, 0, 0};
static const char dir[4] = {'u', 'd', 'l', 'r'};

bool isTarget(Puzzle p) {
  rep(i, N2) if (p.f[i] != (i + 1)) return false;
  return true;
}

string bfs(Puzzle s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    Puzzle u = Q.front();
    Q.pop();
    if (isTarget(u)) return u.path;
    int sx = u.space % N;
    int sy = u.space / N;
    rep(i, 4) {
      int tx = sx + dx[i];
      int ty = sy + dy[i];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      Puzzle v = u;
      swap(v.f[u.space], v.f[tx + ty * N]);
      v.space = tx + ty * N;
      if (!V[v]) {
        V[v] = true;
        v.path += dir[i];
        Q.push(v);
      }
    }
  }
  return "unsolvable";
}

int main() {
  Puzzle in;
  rep(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }
  string ans = bfs(in);
  cout << ans.size() << endl;
  return 0;
}
