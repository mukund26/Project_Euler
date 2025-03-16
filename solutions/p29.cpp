#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> getBaseExponent(int num)
{
  int base = num;
  for (int i = 2; i * i <= num; i++)
  {
    float val = log(num) / log(i);
    if (val == int(val))
    {
      return {i, int(val)};
    }
  }
  return {num, 1};
}

int main()
{
  set<pair<int, int>> uniquePowers;

  for (int a = 2; a <= 100; ++a)
  {
    auto [base, exponent] = getBaseExponent(a);
    for (int b = 2; b <= 100; ++b)
    {
      uniquePowers.insert({base, b * exponent});
    }
  }

  cout << "Distinct terms count: " << uniquePowers.size() << endl;
  return 0;
}
