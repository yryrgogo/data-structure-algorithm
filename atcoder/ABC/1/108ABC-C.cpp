#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  ll N, K;
  cin >> N >> K;
  ll ans = 0;

  if (K % 2 == 1)
  {
    ll q = floor(N / K);
    ans += pow(q, 3);
  }
  else if (K % 2 == 0)
  {
    ll q = floor(N / K);
    ll q2 = floor(N / (K / 2));
    if (q * 2 == q2)
    {
      ans += pow(q, 3) * 2;
    }
    else
    {
      ans += pow(q, 3) + pow(q2 - q, 3);
    }
  }

  cout << ans;
}