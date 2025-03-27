#include<iostream>
using namespace std;

int phi(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ans -= (ans/i);
    }
  }
  if (n > 1) {
    ans -= (ans/n);
  }
  return ans;
}

void bruteForce() {
  double val = 3.0;
  int ans = 6;

  for (int i = 11; i <= 1000000; i++) {
    double temp = (double)i / phi(i);
    if (temp > val) {
      val = temp;
      ans = i;
    }
  }

  cout << ans << endl;
}

int main() {
  
  // bruteForce();

  int ans = 1;
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  for (int i = 0; i < 12; i++) {
    if (ans * primes[i] > 1000000) {
      break;
    }
    ans *= primes[i];
  }

  cout << ans << endl;

  return 0;
}