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

  ll N, K;
  cin >> N >> K;

  ll ans = 0;

  if (K % 2 == 1)
  {
    ll num = floor(N / K);
    ans += pow(num, 3);
  }
  else if (K % 2 == 0)
  {
    ll num = floor(N / (K / 2));
    ll numK = floor(N / K);
    ans += pow(numK, 3);
    ans += pow(num - numK, 3);
  }

  cout << ans;
}
