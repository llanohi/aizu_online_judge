#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
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
const int BOTTOM = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int TOP = 3;

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
    return y - p.y < -EPS || (fabs(y - p.y) < EPS && x - p.x < -EPS);
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

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Point a, Point b) {
  return abs(a - b);
}

double getDistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1)) / abs(l.p2 - l.p1);
}

double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

Point getCrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return (s1.p2 - s1.p1) * t + s1.p1;
}

pair<Point, Point> getCrossPoints(Circle c, Line l) {
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  double base = sqrt(c.r * c.r - norm(pr - c.c));
  Vector x = e * base;
  return make_pair(x + pr, pr - x);
}

double arg(Vector p) {
  return atan2(p.y, p.x);
}

Vector polar(double a, double r) {
  return Point(cos(r) * a, sin(r) * a);
}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
  double d = abs(c1.c - c2.c);
  double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  double t = arg(c2.c - c1.c);
  return make_pair(polar(c1.r, t + a) + c1.c, polar(c1.r, t - a) + c1.c);
}

int contains(Polygon g, Point p) {
  int n = g.size();
  bool x = false;
  rep(i, n) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < EPS & dot(a, b) < EPS) return 1;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
  }
  return (x ? 2 : 0);
}

Polygon andrewScan(Polygon s) {
  int n = s.size();
  if (n < 3) return s;
  sort(s.begin(), s.end());

  Polygon u, l;
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[n - 1]);
  l.push_back(s[n - 2]);

  srep(i, 2, n) {
    int j = u.size();
    while (j >= 2) {
      if (ccw(u[j - 2], u[j - 1], s[i]) != COUNTER_CLOCKWISE) break;
      u.pop_back();
      j--;
    }
    u.push_back(s[i]);
  }

  drep(i, n - 2) {
    int j = l.size();
    while (j >= 2) {
      if (ccw(l[j - 2], l[j - 1], s[i]) != COUNTER_CLOCKWISE) break;
      l.pop_back();
      j--;
    }
    l.push_back(s[i]);
  }

  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

  return l;
}

class EndPoint {
 public:
  Point p;
  int seg, st;
  EndPoint() {
  }
  EndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {
  }

  bool operator<(const EndPoint &ep) const {
    if (p.y == ep.p.y) {
      return st < ep.st;
    } else {
      return p.y < ep.p.y;
    }
  }
};

EndPoint EP[2 * 100000];

int manhattanIntersection(vector<Segment> S) {
  int n = S.size(), k = 0;
  rep(i, n) {
    if (S[i].p1.y == S[i].p2.y) {
      if (S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
    } else if (S[i].p1.y > S[i].p2.y) {
      swap(S[i].p1, S[i].p2);
    }

    if (S[i].p1.y == S[i].p2.y) {
      EP[k++] = EndPoint(S[i].p1, i, LEFT);
      EP[k++] = EndPoint(S[i].p2, i, RIGHT);
    } else {
      EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
      EP[k++] = EndPoint(S[i].p2, i, TOP);
    }
  }

  sort(EP, EP + (2 * n));

  set<int> BT;
  BT.insert(1000000001);
  int cnt = 0;

  rep(i, 2 * n) {
    if (EP[i].st == TOP) {
      BT.erase(EP[i].p.x);
    } else if (EP[i].st == BOTTOM) {
      BT.insert(EP[i].p.x);
    } else if (EP[i].st == LEFT) {
      set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
      set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
      cnt += distance(b, e);
    }
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> s(n);
  int x1, y1, x2, y2;
  rep(i, n) {
    cin >> x1 >> y1 >> x2 >> y2;
    s[i] = Segment(Point(x1, y1), Point(x2, y2));
  }

  cout << manhattanIntersection(s) << endl;
  return 0;
}
