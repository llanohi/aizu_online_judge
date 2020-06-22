#include <bits/stdc++.h>
using namespace std;

int top;
int S[1000];

void push(int x) {
  S[++top] = x;
}

int pop() {
  top--;
  return S[top + 1];
}

int calc(string o) {
  int a = pop();
  int b = pop();
  if (o == "+") {
    return a + b;
  } else if (o == "-") {
    return b - a;
  } else if (o == "*") {
    return a * b;
  }
}

int main() {
  string s;
  while (cin >> s) {
    if (s == "+" || s == "-" || s == "*") {
      push(calc(s));
    } else {
      push(atoi(s.c_str()));
    }
  }

  cout << pop() << endl;

  return 0;
}
