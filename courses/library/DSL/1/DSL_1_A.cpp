#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> P;

class DisjointSet {
 public:
  vi rank, p;

  DisjointSet();
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, size) makeSet(i);
  }

  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y) {
    return findSet(x) == findSet(y);
  }

  void unite(int x, int y) {
    link(findSet(x), findSet(y));
  }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }

  int findSet(int x) {
    if (x != p[x]) p[x] = findSet(p[x]);
    return p[x];
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  DisjointSet ds = DisjointSet(n);
  int com, x, y;
  rep(i, q) {
    cin >> com >> x >> y;
    if (com == 0) {
      ds.unite(x, y);
    } else if (com == 1) {
      cout << (ds.same(x, y) ? 1 : 0) << endl;
    }
  }
  return 0;
}
