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
const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

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

bool isOrthogonal(Segment s1, Segment s2) {
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
}

double abs(Vector a) {
  return sqrt(norm(a));
}

Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / base.norm();
  return base * r + s.p1;
}

Point reflect(Segment s, Point p) {
  return (project(s, p) - p) * 2.0 + p;
}

int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

int main() {
  int x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  Point p0 = Point(x0, y0);
  Point p1 = Point(x1, y1);
  int q;
  cin >> q;
  rep(i, q) {
    int x2, y2;
    cin >> x2 >> y2;
    Point p2 = Point(x2, y2);
    Point ret = ccw(p0, p1, p2);
    if (ret == COUNTER_CLOCKWISE) {
      cout << "COUNTER_CLOCKWISE" << endl;
    } else if (ret == CLOCKWISE) {
      cout << "CLOCKWISE" << endl;
    } else if (ret == ONLINE_BACK) {
      cout << "ONLINE_BACK" << endl;
    } else if (ret == ONLINE_FRONT) {
      cout << "ONLINE_FRONT" << endl;
    } else {
      cout << "ON_SEGMENT" << endl;
    }
  }
  return 0;
}
