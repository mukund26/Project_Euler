#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

vector<vector<int>> ar(80, vector<int>(80, 0));
vector<vector<int>> dp(80, vector<int>(80, -1));

int recur(int r, int c) {
  if (r < 0 || r >= 80 || c < 0 || c >= 80) return INT_MAX;
  if (r == 79 && c == 79) return ar[r][c];
  if (dp[r][c] != -1) return dp[r][c];
  int ans = min(recur(r + 1, c), recur(r, c + 1));
  return dp[r][c] = ans != INT_MAX ? ar[r][c] + ans : ans;
}

int main() {

  ifstream file("matrix.txt");
  string line;
  int i = 0, j = 0;

  while (getline(file, line))
  {
    stringstream ss(line);
    string num;
    while (getline(ss, num, ','))
    {
      ar[i][j] = stoi(num);
      j++;
    }
    i++;
    j = 0;
  }

  file.close();

  cout<<recur(0, 0)<<endl;

  return 0;
}