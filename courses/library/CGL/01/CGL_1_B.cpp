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

Point project(Line l, Point p) {
  Vector base = l.p2 - l.p1;
  double r = dot(p - l.p1, base) / base.norm();
  return base * r + l.p1;
}

Point reflect(Line l, Point p) {
  return (project(l, p) - p) * 2.0 + p;
}

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  Line l = Line(Point(x1, y1), Point(x2, y2));
  int q;
  cin >> q;
  rep(i, q) {
    int x0, y0;
    cin >> x0 >> y0;
    Point p = Point(x0, y0);
    Point k = reflect(l, p);
    printf("%.8lf %.8lf\n", k.x, k.y);
  }
  return 0;
}
