#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MX = 100000;
const int NIL = -1;

vvi R(MX);
vi group(MX);
int n;

void dfs(int user_id, int group_id) {
  if (group[user_id] != NIL) return;
  group[user_id] = group_id;
  rep(i, R[user_id].size()) dfs(R[user_id][i], group_id);
}

void setGroup() {
  int group_id = 0;
  rep(i, n) group[i] = NIL;
  rep(i, n) if (group[i] == NIL) dfs(i, group_id++);
}

int main() {
  int m;
  cin >> n >> m;
  int s, t;
  rep(i, m) {
    cin >> s >> t;
    R[s].push_back(t);
    R[t].push_back(s);
  }

  setGroup();

  int q;
  cin >> q;
  rep(i, q) {
    cin >> s >> t;
    cout << (group[s] == group[t] ? "yes" : "no") << endl;
  }

  return 0;
}
