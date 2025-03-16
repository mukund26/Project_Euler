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

#define ll long long


bool isPentagon(ll n) {
  double discriminant = (sqrt(1 + 24 * n) + 1) / 6;
  return discriminant == (ll)discriminant;
}

int main() {
  
  int n = 144;

  for (ll i = n; ; i++) {
    int h = i * (2 * i - 1);
    if (isPentagon(h)) {
      cout<<h<<endl;
      break;
    }
  }

  return 0;
}