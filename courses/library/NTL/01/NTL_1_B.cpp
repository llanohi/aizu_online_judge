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
const int MOD = 1000000007;

ull power(ull x, ull n) {
  if (n == 0) return 1;
  ull res = power(x * x % MOD, n / 2);
  if (n % 2 == 1) res = res * x % MOD;
  return res;
}

int main() {
  int m, n;
  cin >> m >> n;

  cout << power(m, n) << endl;
  return 0;
}
