#include<iostream>
using namespace std;

bool haveSameDigits(int n) {
  string b = to_string(2 * n), c = to_string(3 * n), d = to_string(4 * n), e = to_string(5 * n), f = to_string(6 * n);
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  sort(e.begin(), e.end());
  sort(f.begin(), f.end());
  return b == c && c == d && d == e && e == f;
}

int main() {

  for (int i = 1000; i < 1000000; i++) {
    if (haveSameDigits(i)) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}