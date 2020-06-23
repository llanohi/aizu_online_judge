#include <bits/stdc++.h>
using namespace std;

int top;
int S[1000];

int calc(string o, int a, int b) {
  if (o == "+") {
    return a + b;
  } else if (o == "-") {
    return b - a;
  } else if (o == "*") {
    return a * b;
  }
}

int main() {
  stack<int> S;
  string s;
  while (cin >> s) {
    if (s == "+" || s == "-" || s == "*") {
      int a = S.top();
      S.pop();
      int b = S.top();
      S.pop();
      S.push(calc(s, a, b));
    } else {
      S.push(atoi(s.c_str()));
    }
  }

  cout << S.top() << endl;

  return 0;
}
