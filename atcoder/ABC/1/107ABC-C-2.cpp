#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

int main()
{

  int N, K;
  cin >> N >> K;

  int x[N];
  rep(i, N)
  {
    cin >> x[i];
  }
  int left = 0;
  int right = 0;
  int leftCnt = 0;
  int rightCnt = 0;
  int cost = 0;
  int ans = 1000000007;
  repd(i, 0, N - K + 1)
  {
    if (x[i] >= 0){
      cost = abs(x[K + i - 1]);
    }
    else if (x[K + i - 1] >= 0)
    {
      if (abs(x[i]) > abs(x[K + i - 1]))
      {
        cost = abs(x[K + i - 1]) * 2 + abs(x[i]);
      }
      else
      {
        cost = abs(x[K + i - 1]) + abs(x[i]) * 2;
      }
    }
    else if (x[K + i - 1] < 0)
    {
      cost = abs(x[i]);
    }

    if (cost < ans)
    {
      ans = cost;
    }
  }
  cout << ans;
}