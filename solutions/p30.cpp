#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

long fifthSum(long n)
{
  long sum = 0;
  while (n > 0)
  {
    sum += pow(n % 10, 5);
    n /= 10;
  }
  return sum;
}


int main()
{
  long ans = 0;

  for (int a = 1000; a <= 999999; ++a)
  {
    if (a == fifthSum(a)) {
      cout << a << endl;
      ans += a;
    }
  }

  cout << ans << endl;
  return 0;
}
