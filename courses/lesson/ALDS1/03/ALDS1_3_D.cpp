#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> P;

int main() {
  stack<int> x;
  stack<P> l;
  int total = 0;
  char c;
  int i = 0;
  while (cin >> c) {
    if (c == '\\') {
      x.push(i);
    } else if (c == '/' and x.size() > 0) {
      int j = x.top();
      x.pop();
      int tmp = i - j;
      total += tmp;
      while (l.size() > 0 && l.top().first > j) {
        tmp += l.top().second;
        l.pop();
      }
      l.push(make_pair(j, tmp));
    }
    i++;
  }

  vector<int> ans;
  while (l.size() > 0) {
    ans.push_back(l.top().second);
    l.pop();
  }
  reverse(ans.begin(), ans.end());

  cout << total << endl;
  cout << ans.size();
  rep(i, (int)ans.size()) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}
