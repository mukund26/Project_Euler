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

vector<bool> primes(10000, true);

void calcPrime() {
  primes[0] = primes[1] = false;
  for (int i = 2; i < 10000; i++) {
    if (!primes[i]) {
      continue;
    }
    for (int j = 2; j * i < 10000; j++) {
      primes[j * i] = false;
    }
  }
}

int main() {

  calcPrime();
  
  for (int i = 1000; i < 10000; i++) {
    if (primes[i]) {
      int b = i + 3330;
      int c = b + 3330;
      if (primes[b] && primes[c]) {
        string s = to_string(i);
        string t = to_string(b);
        string u = to_string(c);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        sort(u.begin(), u.end());
        if (s == t && t == u) {
          cout << i << b << c << endl;
        }
      }
    }
  }

  return 0;
}