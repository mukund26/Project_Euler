#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000000;

vector<bool> primes(N + 1, true);

unordered_set<int> primesSet;

void calcPrimes() {
  primes[0] = primes[1] = false;
  for (int i = 2; i < N + 1; i++) {
    if (primes[i]) {
      primesSet.insert(i);
      for (int j = 2 * i; j < N + 1; j += i) {
        primes[j] = false;
      }
    }
  }
}

vector<int> getRotations(int n) {
  vector<int> rotations;
  string s = to_string(n);
  int len = s.size();

  for (int i = 0; i < len; i++) {
    rotations.push_back(stoi(s));
    rotate(s.begin(), s.begin() + 1, s.end());
  }

  return rotations;
}

int main()
{
  int ans = 0;

  calcPrimes();

  for (auto &x: primesSet) {
    bool isAllPrime = true;
    vector<int> rotations = getRotations(x);
    for (int num : rotations) {
      if (primesSet.find(num) == primesSet.end()) {
        isAllPrime = false;
        break;
      }
    }
    if (isAllPrime) ans++;
  }
  
  cout << ans << endl;

  return 0;
}
