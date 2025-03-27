#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

vector<bool> primes(MAX, true);

void calcPrime()
{
  primes[0] = primes[1] = false;
  for (int i = 2; i < MAX; i++)
  {
    if (!primes[i])
    {
      continue;
    }
    for (int j = 2; j * i < MAX; j++)
    {
      primes[j * i] = false;
    }
  }
}

int main()
{

  calcPrime();

  for (int i = 35;; i += 2)
  {
    bool found = false;
    if (primes[i])
    {
      continue;
    }
    // cout << i << " : ";
    for (int j = 1; j <= i; j++)
    {
      int val = 2 * pow(j, 2);
      if (val >= i)
      {
        break;
      }
      // cout << "(" << val << ", " << i - val << ") ";
      if (primes[i - val])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}