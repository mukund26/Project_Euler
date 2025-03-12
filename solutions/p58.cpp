
#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int primes = 0, total = 1, i = 3, dif = 2, count = 1;
    do {
        count += (dif - 1);
        int a = i;
        int b = a + dif;
        int c = b + dif;
        int d = c + dif;
        total += 4;
        if (checkPrime(a)) primes++;
        if (checkPrime(b)) primes++;
        if (checkPrime(c)) primes++;
        if (checkPrime(d)) primes++;
        count+=(d - a + 1);
        dif += 2;
        i = d + dif;
    } while (10 * primes >= total);
    cout<<primes<<" "<<total<<" "<<count<<endl;
    return 0;
}
