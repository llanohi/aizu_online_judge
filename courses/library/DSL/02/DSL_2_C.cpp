#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 1000000;
const int NIL = -1;

class Node {
 public:
  int location;
  int p, l, r;
  Node() {
  }
};

class Point {
 public:
  int id, x, y;
  Point() {
  }
  Point(int id, int x, int y) : id(id), x(x), y(y) {
  }
  bool operator<(const Point &p) const {
    return id < p.id;
  }

  void print() {
    printf("%d\n", id);
  }
};

int n;
Point P[MX];
Node T[MX];
int np;

bool lessX(const Point &p1, const Point &p2) {
  return p1.x < p2.x;
}
bool lessY(const Point &p1, const Point &p2) {
  return p1.y < p2.y;
}

int makeKDTree(int l, int r, int depth) {
  if (!(l < r)) return NIL;
  int mid = (l + r) / 2;
  int t = np++;
  if (depth % 2 == 0) {
    sort(P + l, P + r, lessX);
  } else {
    sort(P + l, P + r, lessY);
  }
  T[t].location = mid;
  T[t].l = makeKDTree(l, mid, depth + 1);
  T[t].r = makeKDTree(mid + 1, r, depth + 1);

  return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth,
          vector<Point> &ans) {
  int x = P[T[v].location].x;
  int y = P[T[v].location].y;

  if (sx <= x && x <= tx && sy <= y && y <= ty) {
    ans.push_back(P[T[v].location]);
  }

  if (depth % 2 == 0) {
    if (T[v].l != NIL && sx <= x) {
      find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL && x <= tx) {
      find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  } else {
    if (T[v].l != NIL && sy <= y) {
      find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL && y <= ty) {
      find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  }
}

int main() {
  cin >> n;
  int x, y;
  rep(i, n) {
    scanf("%d %d", &x, &y);
    P[i] = Point(i, x, y);
    T[i].l = T[i].r = T[i].p = NIL;
  }

  np = 0;

  int root = makeKDTree(0, n, 0);

  int q;
  cin >> q;
  vector<Point> ans;
  rep(i, q) {
    int sx, tx, sy, ty;
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(root, sx, tx, sy, ty, 0, ans);
    sort(ans.begin(), ans.end());
    rep(j, ans.size()) ans[j].print();
    printf("\n");
  }

  return 0;
}
