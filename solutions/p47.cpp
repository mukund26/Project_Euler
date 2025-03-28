#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFactors(int n) {
  int count = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) count++;
  return count;
}

int main()
{

  unordered_map<int, vector<int>> primeMap;

  for (int i = 1000; i < 1000000; i++) {
    primeMap[countFactors(i)].push_back(i);
  }

  int cur = -1, count = 0;
  for (auto& p : primeMap[4]) {
    if (cur == -1 || p - cur == 1) {
      count++;
    } else {
      count = 1;
    }
    cur = p;
    if (count == 4) {
      cout << p - 3 << endl;
      break;
    }
  }

  cout << endl;

  return 0;
}