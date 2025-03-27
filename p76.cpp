#include <iostream>
#include <vector>

using namespace std;

int main()
{
  const int N = 100;
  vector<int> ways(N + 1, 0);
  ways[0] = 1; // Base case

  for (int i = 1; i < N; ++i)
  { // Exclude N itself
    for (int j = i; j <= N; ++j)
    {
      ways[j] += ways[j - i];
    }
  }

  cout << "Number of ways to write " << N << " as a sum of at least two positive integers: " << ways[N] << endl;
  return 0;
}
