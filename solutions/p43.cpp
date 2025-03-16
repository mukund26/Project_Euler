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

int main()
{

  long ans = 0;

  string s = "0123456789";

  do {
    long a = stol(s.substr(1, 3));
    long b = stol(s.substr(2, 3));
    long c = stol(s.substr(3, 3));
    long d = stol(s.substr(4, 3));
    long e = stol(s.substr(5, 3));
    long f = stol(s.substr(6, 3));
    long g = stol(s.substr(7, 3));
    if (a % 2 == 0 && b % 3 == 0 && c % 5 == 0 && d % 7 == 0 && e % 11 == 0 && f % 13 == 0 && g % 17 == 0) {
      // cout<<s<<endl;
      ans += stol(s);
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << ans << endl;

  return 0;
}