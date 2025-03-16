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

int getWordValue(string word) {
  int ans = 0;
  for (auto &x: word) {
    ans += (x - 'A' + 1);
  }
  return ans;
}

bool isTriangular(int n) {
  int discriminant = (int) sqrt(1 + 8 * n);
  int root1 = (-1 + discriminant) / 2;
  int root2 = (-1 - discriminant) / 2;
  int val1 = (root1 * (root1 + 1)) / 2;
  int val2 = (root2 * (root2 + 1)) / 2;
  return val1 == n || val2 == n;
}

int main() {
  std::ifstream file("words.txt");
  std::string str;
  std::vector<std::string> words;

  while (std::getline(file, str)) {
    std::stringstream ss(str);
    std::string word;
    while (std::getline(ss, word, ',')) {
      word = word.substr(1, word.size() - 2);
      words.push_back(word);
    }
  }

  file.close();

  int ans = 0;
  for (auto &word: words) {
    int val = getWordValue(word);
    if (isTriangular(val)) {
      ans++;
    }
  }

  cout<<ans<<endl;

  return 0;
}