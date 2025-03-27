#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 100;

vector<bool> prime;
set<int> primes;

void primeCalculator() {

  prime.assign(100, true);

  prime[0] = prime[1] = false;

  for (int i = 2; i < 100; i++)
  {
    if (!prime[i])
    {
      continue;
    }
    primes.insert(i);
    for (int j = 2; j * i < 100; j++)
    {
      prime[j * i] = false;
    }
  }
}

int main()
{
  primeCalculator();

  int ans = 0;
  vector<long long> ways(N + 1, 0);
  ways[0] = 1; // Base case

  for (auto &x: primes)
  {
    for (int j = 1; j <= N; ++j)
    {
      if (j - x >= 0){
        ways[j] += ways[j - x];
        if (ways[j] == 5000) {
          ans = j;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
