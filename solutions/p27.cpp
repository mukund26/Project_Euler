#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

bool checkPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int totalPrimes(int a, int b) {
  int n1 = 0;
  while (checkPrime(n1 * n1 + a * n1 + b)) {
    n1++;
  }
  return n1;
}

int main() {
  
  int ans = INT_MIN, a = -1, b = -1;

  for (int i = -999; i <= 999; i++) {
    for (int j = -1000; j <= 1000; j++) {
      int res = totalPrimes(i, j);
      if (res > ans) {
        ans = res;
        a = i;
        b = j;
      }
    }
  }

  cout<<a * b<<endl;

  return 0;
}