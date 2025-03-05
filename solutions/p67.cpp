#include <bits/stdc++.h>
using namespace std;

int main() 
{
  
  std::ifstream file("sample1.txt");
    std::vector<std::vector<int>> ar;
    
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
          row.push_back(num);
        }
        ar.push_back(row);
    }

    file.close();
    
    vector<vector<int> > dp(ar.size(), vector<int> (ar[ar.size() - 1].size(), 0));
    dp[0][0] = ar[0][0];
    int ans = 0;
    for (int i = 1; i < ar.size(); i++) {
      for (int j = 0; j < min(100, (int)ar[i].size()); j++) {
        dp[i][j] = ar[i][j] + max(dp[i - 1][max(0, j - 1)], dp[i - 1][j]);
        ans = max(ans, dp[i][j]);
      }
    }
    cout<<ans<<endl;
    return 0;
}
