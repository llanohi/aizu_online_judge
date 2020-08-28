#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin >> n;

  char cmd[20];
  int key;
  list<int> L;
  rep(i, n) {
    scanf("%s%d", cmd, &key);
    if (cmd[0] == 'i') {
      L.push_front(key);
    } else if (cmd[0] == 'd') {
      if (strlen(cmd) > 6) {
        if (cmd[6] == 'F') {
          L.pop_front();
        } else {
          L.pop_back();
        }
      } else {
        for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
          if (*it == key) {
            L.erase(it);
            break;
          }
        }
      }
    }
  }

  int i = 0;
  for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
    if (i++ > 0) {
      printf(" ");
    }
    printf("%d", *it);
  }
  printf("\n");

  return 0;
}
