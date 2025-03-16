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

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  
  int start = 123456789;
  int ans = -1;

  while (start > 0) {
    string s = to_string(start);
    bool isPrimeVal = false;
    do {
      int num = stoi(s);
      if (isPrime(num)) {
        isPrimeVal = true;
        ans = max(ans, num);
      }
    } while (next_permutation(s.begin(), s.end()));
    if (isPrimeVal) {
      break;
    }
    start /= 10;
  }

  cout<<ans<<endl;

  return 0;
}