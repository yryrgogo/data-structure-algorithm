#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int h[N];
  int cnt = 0;
  int inner = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> h[i];
  }

  for (int i = 0; i < N; i++)
  {
    if (inner >= h[i])
    {
      inner = h[i];
    }
    else
    {
      cnt += h[i] - inner;
      inner = h[i];
    }
  }
  cout << cnt;
}