#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef vector<int> vi;
typedef long long ll;

const int M = 1000003;
const int L = 14;
char table[M][L];

int getChar(char ch) {
  if (ch == 'A') {
    return 1;
  } else if (ch == 'C') {
    return 2;
  } else if (ch == 'G') {
    return 3;
  } else if (ch == 'T') {
    return 4;
  } else {
    return 0;
  }
}

ll getKey(char value[]) {
  ll key = 0, p = 1;
  rep(i, (int)strlen(value)) {
    key += p * getChar(value[i]);
    p *= 5;
  }
  return key;
}

int h1(int key) {
  return key % M;
}

int h2(int key) {
  return 1 + (key % (M - 1));
}

void insert(char value[]) {
  ll key, h;
  key = getKey(value);
  for (int i = 0; i < M; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(table[h], value) == 0) {
      return;
    } else if (strlen(table[h]) == 0) {
      strcpy(table[h], value);
      return;
    }
  }
  return;
}

bool find(char value[]) {
  ll key, h;
  key = getKey(value);
  for (int i = 0; i < M; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(table[h], value) == 0) {
      return true;
    } else if (strlen(table[h]) == 0) {
      return false;
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  char cmd[9], str[L];
  rep(i, n) {
    scanf("%s %s", cmd, str);
    if (cmd[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}
