#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  string s = "";
  int ans = 1, val = 0;

  for (int i = 1; i <= 1000000; i++) {
    s += to_string(i);
    int p = pow(10, val);
    if (s.size() >= p) {
      ans = ans * (s[p - 1] - '0');
      val++;
    }
  }

  cout << ans << endl;

  return 0;
}
