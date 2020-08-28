#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

const int LEN = 1000002;

struct proc {
  string name;
  int time;

  proc(string name, int time) {
    this->name = name;
    this->time = time;
  }
};

int main() {
  queue<proc> Q;
  int n, q;
  cin >> n >> q;
  string name;
  int time;
  rep(i, n) {
    cin >> name >> time;
    Q.push(proc(name, time));
  }

  int elaps = 0;
  while (!Q.empty()) {
    proc p = Q.front();
    Q.pop();
    int t = min(p.time, q);
    p.time -= t;
    elaps += t;

    if (p.time > 0) {
      Q.push(p);
    } else {
      cout << p.name << " " << elaps << endl;
    }
  }

  return 0;
}
