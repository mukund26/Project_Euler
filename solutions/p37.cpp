#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000000;

vector<bool> primes(N + 1, true);

set<int> primesSet;

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

int main()
{
  int ans = 0, count = 0;

  calcPrimes();

  for (auto &x: primesSet) {
    int temp = x, p = log10(x) + 1, temp2 = x;
    bool isAllPrime = true;
    while (temp) {
      if (primesSet.find(temp) == primesSet.end()) {
        isAllPrime = false;
        break;
      }
      temp /= 10;
    }
    while (temp2) {
      if (primesSet.find(temp2) == primesSet.end()) {
        isAllPrime = false;
        break;
      }
      temp2 %= (int)pow(10, p - 1);
      p--;
    }
    if (isAllPrime && x > 10 && count < 11) {
      cout<<x<<endl;
      count++;
      ans += x;
    }
  }
  
  cout << ans << " " << count << endl;

  return 0;
}
