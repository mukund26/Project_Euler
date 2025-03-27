#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cycleLength(int n)
{
  int k = 1;
  int val = 10;
  while (true)
  {
    int rem = val % n;
    if (rem == 1 || rem == 0) {
      break;
    }
    val = rem * 10;
    k++;
  }
  return k;
}

int main()
{

  int ans = 7, len = 6;

  vector<bool> prime(1000, true);

  prime[0] = prime[1] = false;

  for (int i = 2; i < 1000; i++)
  {
    if (!prime[i])
    {
      continue;
    }
    int cur = cycleLength(i);
    if (cur > len)
    {
      ans = i;
      len = cur;
    }
    for (int j = 2; j * i < 1000; j++)
    {
      prime[j * i] = false;
    }
  }

  cout << ans << " " << len << endl;

  return 0;
}