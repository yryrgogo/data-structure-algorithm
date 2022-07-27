#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> h(N);

  for (int i = 0; i < N; i++)
  {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  int ans = 1000000000;
  for (int i = 0; i < N - K + 1; i++)
  {
    int diff = h[i + K - 1] - h[i];
    if (ans > diff)
    {
      ans = diff;
    }
  }

  cout << ans;
}
