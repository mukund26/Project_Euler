#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int ans = 0, val = 0;
  unordered_map<int, int> count;

  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      for (int k = 1; k <= 500; k++) {
        if (i * i + j * j == k * k) {
          ++count[i + j + k];
        }
      }
    }
  }

  for (auto &x: count) {
    if (x.second > val) {
      val = x.second;
      ans = x.first;
    }
  }

  cout << ans << " " << val << endl;

  return 0;
}
