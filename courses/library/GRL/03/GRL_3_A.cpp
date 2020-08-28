#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 10000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

vi g[MX];
int n;
bool isVisited[MX];
int prenum[MX], parent[MX], lowest[MX], timer;

void dfs(int current, int prev) {
  prenum[current] = lowest[current] = timer;
  timer++;

  isVisited[current] = true;

  rep(i, g[current].size()) {
    int next = g[current][i];
    if (!isVisited[next]) {
      parent[next] = current;
      dfs(next, current);
      lowest[current] = min(lowest[current], lowest[next]);
    } else if (next != prev) {
      lowest[current] = min(lowest[current], prenum[next]);
    }
  }
}

void art_points() {
  rep(i, n) isVisited[i] = false;
  timer = 1;
  dfs(0, -1);

  set<int> ap;
  int np = 0;
  srep(i, 1, n) {
    int p = parent[i];
    if (p == 0) {
      np++;
    } else if (prenum[p] <= lowest[i]) {
      ap.insert(p);
    }
  }
  if (np > 1) ap.insert(0);
  for (set<int>::iterator it = ap.begin(); it != ap.end(); it++) {
    cout << *it << endl;
  }
}

int main() {
  int m;
  cin >> n >> m;
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    g[s].push_back(t);
    g[t].push_back(s);
  }

  art_points();

  return 0;
}
