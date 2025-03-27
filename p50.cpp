#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

vector<bool> primes(MAX, true);

vector<int> primeSet;

void calcPrime()
{
  primes[0] = primes[1] = false;
  for (int i = 2; i < MAX; i++)
  {
    if (!primes[i])
    {
      continue;
    }
    primeSet.push_back(i);
    for (int j = 2; j * i < MAX; j++)
    {
      primes[j * i] = false;
    }
  }
}

int main()
{

  calcPrime();

  int ans, count = 0, s = 0, n = primeSet.size();

  for (int i = 0; i < n; i++) {
    s = 0;
    for (int j = i; j < n; j++) {
      s += primeSet[j];
      if (s >= MAX) {
        break;
      }
      if (primes[s] && j - i + 1 > count) {
        count = j - i + 1;
        ans = s;
      }
    }
  }

  cout << ans << " " << count << endl;

  return 0;
}