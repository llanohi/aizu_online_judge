#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;

struct Card {
  char suit, value;
};

void printList(struct Card C[], int n) {
  rep(i, n) {
    if (i > 0) {
      cout << " ";
    }
    cout << C[i].suit << C[i].value;
  }
  cout << endl;
}

void bubbleSort(struct Card C[], int n) {
  rep(i, n) for (int j = n - 1; j > i; j--) {
    if (C[j].value < C[j - 1].value) {
      swap(C[j], C[j - 1]);
    }
  }
}

void selectionSort(struct Card C[], int n) {
  rep(i, n - 1) {
    int minj = i;
    srep(j, i + 1, n) {
      if (C[j].value < C[minj].value) {
        minj = j;
      }
    }
    swap(C[i], C[minj]);
  }
}

bool isStable(struct Card C1[], struct Card C2[], int n) {
  rep(i, n) {
    if (C1[i].suit != C2[i].suit) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  Card C1[n], C2[n];
  rep(i, n) cin >> C1[i].suit >> C1[i].value;
  rep(i, n) C2[i] = C1[i];

  bubbleSort(C1, n);
  printList(C1, n);
  cout << "Stable" << endl;

  selectionSort(C2, n);
  printList(C2, n);
  if (isStable(C1, C2, n)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}
