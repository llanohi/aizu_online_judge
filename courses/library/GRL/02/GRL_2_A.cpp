#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

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

class Edge {
 public:
  int source, target, cost;
  Edge(int source = 0, int target = 0, int cost = 0)
      : source(source), target(target), cost(cost) {
  }
  bool operator<(const Edge &e) const {
    return cost < e.cost;
  }
};

int kruskal(int n, vector<Edge> edges) {
  int totalCost = 0;
  sort(edges.begin(), edges.end());
  DisjointSet dset = DisjointSet(n + 1);

  rep(i, n) dset.makeSet(i);

  int source, target;
  rep(i, edges.size()) {
    Edge e = edges[i];
    if (!dset.same(e.source, e.target)) {
      totalCost += e.cost;
      dset.unite(e.source, e.target);
    }
  }
  return totalCost;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  rep(i, m) {
    int s, t, w;
    cin >> s >> t >> w;
    edges.push_back(Edge(s, t, w));
  }

  cout << kruskal(n, edges) << endl;

  return 0;
}
