#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int x, int y)
{
  return x ? gcd(y % x, x) : y;
}

int main()
{

  int N, X;
  cin >> N >> X;
  int x[N];
  // vector<int> x;

  int code = 0;
  int diff[N];

  for (int i = 0; i < N; i++)
  {
    cin >> x[i];
    diff[i] = abs(X - x[i]);
  }

  if (N == 1)
  {
    cout << diff[0];
    return 0;
  }

  int step = 0;
  for (int i = 0; i < N - 1; i++)
  {
    if (step == 0)
    {
      step = gcd(diff[i], diff[i + 1]);
    }
    else
    {
      step = gcd(step, diff[i + 1]);
    }
  }

  cout << step;

  return 0;
}