#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;

int main() {

  fstream file("base.txt");
  string line;
  int i = 1;
  double maxVal = 0;
  int ans = -1;

  while (getline(file, line)) {
    int n = line.length();
    string base = "", exp = "";
    for (int i = 0; i < n; i++) {
      if (line[i] == ',') {
        base = line.substr(0, i);
        exp = line.substr(i + 1, n - i - 1);
        break;
      }
    }
    int b = stoi(base), e = stoi(exp);
    double val = e * log(b);
    if (val > maxVal) {
      maxVal = val;
      ans = i;
    }
    i++;
  }

  cout << ans << " " << maxVal << endl;

  return 0;
}