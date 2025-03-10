// Number Spiral Diagonals

#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAX = 1001 * 1001;
    long ans = 0, k = 0, dif = 2;
    for (int i = 1; i <= MAX;) {
        // cout<<i<<" - "<<dif<<endl;
        ans += i;
        i += dif;
        k++;
        if (k == 4)  { 
            dif += 2;
            k = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
