#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int gcd(int x, int y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int main()
{

  ll N;
  cin >> N;

  ll A[N];
  rep(i, N) cin >> A[i];

  ll n_gcd = A[0];
  rep(i, N)
  {
    n_gcd = gcd(n_gcd, A[i]);
  }

  cout << n_gcd;
}
