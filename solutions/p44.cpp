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

int pentagon(int n) {
  return n * (3 * n - 1) / 2;
}

int main() {
  
  set<int> pentagons;

  for (int i = 1; i <= 10000; i++) {
    pentagons.insert(pentagon(i));
  }

  int D = INT_MAX;

  for (int i = 1; i <= 10000; i++) {
    for (int j = i + 1; j <= 10000; j++) {
      int sum = pentagon(i) + pentagon(j);
      int diff = abs(pentagon(i) - pentagon(j));
      if (pentagons.count(sum) && pentagons.count(diff)) {
        if (diff < D) {
          D = diff;
        }
      }
    }
  }

  cout<<D<<endl;

  return 0;
}