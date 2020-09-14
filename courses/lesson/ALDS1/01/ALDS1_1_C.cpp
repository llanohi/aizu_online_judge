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

bool isPrime(int x) {
  if (x == 2) return true;
  if (x < 2 or x % 2 == 0) return false;
  int i = 3;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i += 2;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n) {
    int x;
    cin >> x;
    if (isPrime(x)) ans++;
  }

  cout << ans << endl;
  return 0;
}
