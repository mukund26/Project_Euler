#include <bits/stdc++.h>
using namespace std;

std::vector<int> multiplyVectors(const std::vector<int>& num1, const std::vector<int>& num2) {
    int n = num1.size(), m = num2.size();
    std::vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = num1[i] * num2[j];
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10; 
            result[i + j] += sum / 10; 
        }
    }

    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    return result;
}

vector<int> createVector(int n) {
    vector<int> ans;
    while (n) {
        int r = n % 10;
        ans.push_back(r);
        n /= 10;
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{
    vector<int> a = {1};
    
    for (int i = 2; i <= 100; i++) {
        vector<int> b = createVector(i);
        a = multiplyVectors(a, b);
    }
    
    int ans = 0;
    for (auto &x: a) {
       ans += x;
       
    }  
    
    cout<<ans<<endl;
    return 0;
}
