#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

struct Rectangle {
  int height;
  int pos;
};

int main() {
  int H, W;
  scanf("%d %d", &H, &W);
  int C[H][W];
  rep(h, H) rep(w, W) scanf("%d", &C[h][w]);

  int T[H][W + 1];
  rep(h, H) rep(w, W) {
    if (C[h][w] == 1) {
      T[h][w] = 0;
    } else {
      T[h][w] = (h > 0) ? T[h - 1][w] + 1 : 1;
    }
  }

  int maxv = 0;
  rep(h, H) {
    T[h][W] = 0;
    stack<Rectangle> S;
    rep(w, W + 1) {
      Rectangle rect;
      rect.height = T[h][w];
      rect.pos = w;
      if (S.empty()) {
        S.push(rect);
      } else {
        if (S.top().height < rect.height) {
          S.push(rect);
        } else if (S.top().height > rect.height) {
          int target = w;
          while (!S.empty() && S.top().height >= rect.height) {
            Rectangle pre = S.top();
            S.pop();
            int area = pre.height * (w - pre.pos);
            maxv = max(maxv, area);
            target = pre.pos;
          }
          rect.pos = target;
          S.push(rect);
        }
      }
    }
  }

  printf("%d\n", maxv);
  return 0;
}
