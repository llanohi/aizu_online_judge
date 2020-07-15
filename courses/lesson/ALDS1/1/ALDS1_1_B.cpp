#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
  int a = max(x, y), b = min(x, y);
  int c = a % b;
  if (c == 0) return b;
  gcd(b, c);
}

int main() {
  int x, y;
  cin >> x >> y;
  int ans = gcd(x, y);
  cout << ans << endl;
  return 0;
}
