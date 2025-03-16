#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

bool isPandigital(int a, int b, int c) {
  unordered_set<int> st;
  while (a > 0) {
    int r = a % 10;
    if (r == 0 || st.find(r) != st.end()) {
      return false;
    }
    st.insert(r);
    a /= 10;
  }
  while (b > 0) {
    int r = b % 10;
    if (r == 0 || st.find(r) != st.end()) {
      return false;
    }
    st.insert(r);
    b /= 10;
  }
  while (c > 0) {
    int r = c % 10;
    if (r == 0 || st.find(r) != st.end()) {
      return false;
    }
    st.insert(r);
    c /= 10;
  }
  return st.size() == 9 && st.find(0) == st.end();
}

int main()
{
  long ans = 0;
  unordered_set<int> st;

  for (int i = 1; i < 9; i++) {
    for (int j = 1000; j < 10000; j++) {
      int res = i * j;
      if (isPandigital(i, j, res)) {
        cout << i << " * " << j << " = " << res << endl;
        ans += res;
      }
    }
  }

  for (int i = 10; i < 100; i++) {
    for (int j = 100; j < 1000; j++) {
      int res = i * j;
      if (isPandigital(i, j, res)) {
        cout << i << " * " << j << " = " << res << endl;
        st.insert(res);
      }
    }
  }

  for (auto &x: st) ans += x;
  cout << ans << endl;
  return 0;
}