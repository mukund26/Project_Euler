#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

bool isCuriousFraction(int num, int den) {
  int num1 = num / 10;
  int num2 = num % 10;
  int den1 = den / 10;
  int den2 = den % 10;

  if (num1 == den1) {
    if (num2 * den == num * den2) return true;
  }
  if (num1 == den2) {
    if (num2 * den == num * den1) return true;
  }
  if (num2 == den1) {
    if (num1 * den == num * den2) return true;
  }
  if (num2 == den2) {
    if (num1 * den == num * den1) return true;
  }

  return false;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main()
{
  int num = 1, den = 1;

  for (int i = 11; i <= 99; i++) {
    for (int j = 11; j <= 99; j++) {
      if (i % 10 == 0 || j % 10 == 0) continue;
      if (i == j) continue;
      if (i / j >= 1) continue;
      if (isCuriousFraction(i, j)) {
        cout << i << " " << j << endl;
        num *= i;
        den *= j;
      }
    }
  }

  int common = gcd(num, den);
  cout << den / common << endl;

  return 0;
}
