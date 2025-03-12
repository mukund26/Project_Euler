#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

int getPalindrome(int n) {
    int ans = 0;
    while(n) {
        int r = n % 10;
        ans = ans * 10 + r;
        n /= 10;
    }
    return ans;
}

bool binaryPalin(int n) {
    string val = "";
    while (n) {
        int r = n % 2;
        val += (r + '0');
        n /= 2;
    }
    int size = val.length();
    for (int i = 0; i < size / 2; i++) {
        if (val[i] != val[size - i - 1]) return false;
    }
    return true;
}

bool isPalin(int n) {
    if (n == getPalindrome(n)) {
        return binaryPalin(n);
    }
    return false;
}

int main()
{
    int ans = 0;
    
    for (int i = 1; i <= MAX; i++) {
        ans += isPalin(i) ? i : 0;
    }
    
    cout<<ans<<endl;
    return 0;
}
