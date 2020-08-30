#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {
  }
  Point operator+(Point &p) {
    return Point(x + p.x, y + p.y);
  }
  Point operator-(Point &p) {
    return Point(x - p.x, y - p.y);
  }
  Point operator*(double a) {
    return Point(x * a, y * a);
  }
  Point operator/(double a) {
    return Point(x / a, y / a);
  }

  double abs() {
    return sqrt(norm());
  }
  double norm() {
    return x * x + y * y;
  }

  bool operator<(const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

typedef Point Vector;
typedef vector<Point> Polygon;

class Segment {
 public:
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {
  }
};

typedef Segment Line;

class Circle {
 public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {
  }
};

double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(Line l1, Line l2) {
  return equals(dot(l1.p2 - l1.p1, l2.p2 - l2.p1), 0.0);
}

bool isParallel(Line l1, Line l2) {
  return equals(cross(l1.p2 - l1.p1, l2.p2 - l2.p1), 0.0);
}

int main() {
  int q;
  cin >> q;
  rep(i, q) {
    int x0, y0, x1, y1, x2, y2, x3, y3;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Line l1 = Line(Point(x0, y0), Point(x1, y1));
    Line l2 = Line(Point(x2, y2), Point(x3, y3));
    if (isParallel(l1, l2)) {
      cout << 2 << endl;
    } else if (isOrthogonal(l1, l2)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
