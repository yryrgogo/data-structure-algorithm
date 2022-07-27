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

ll gcd(ll a, ll b)
{
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main()
{

  ll N, X;
  cin >> N >> X;

  ll x[N];
  vector<ll> d(N);
  rep(i, N)
  {
    cin >> x[i];
    d[i] = abs(x[i] - X);
  };

  if (d.size() == 1)
  {
    cout << d[0];
    return 0;
  }

  ll ans = gcd(d[0], d[1]);
  repd(i, 2, N)
  {
    ans = gcd(ans, d[i]);
  }
  cout << ans;

  return 0;
}