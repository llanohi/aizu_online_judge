#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

const int LEN = 1000002;

struct proc {
  string name;
  int time;
};

int head, tail;
proc Q[LEN];

void enqueue(proc x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

proc dequeue() {
  proc x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main() {
  int n, q;
  cin >> n >> q;
  rep(i, n) cin >> Q[i].name >> Q[i].time;

  tail = n;
  int elaps = 0;
  while (head != tail) {
    proc p = dequeue();
    int t = min(p.time, q);
    p.time -= t;
    elaps += t;

    if (p.time > 0) {
      enqueue(p);
    } else {
      cout << p.name << " " << elaps << endl;
    }
  }

  return 0;
}
