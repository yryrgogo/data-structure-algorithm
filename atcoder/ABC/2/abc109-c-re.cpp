// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int gcd(int x, int y)
{
  if (y == 0)
  {
    return x;
  }

  return gcd(y, x % y);
}

int main()
{
  int N, X;
  cin >> N >> X;

  int x[N];

  rep(i, N)
  {
    int z;
    cin >> z;
    x[i] = abs(z - X);
  }

  int ans = x[0];

  rep(i, N - 1)
  {
    int a, b;
    if (i == 0)
    {
      if (x[i] >= x[i + 1])
      {
        ans = gcd(x[i], x[i + 1]);
      }
      else
      {
        ans = gcd(x[i + 1], x[i]);
      }
    }
    else
    {
      if (x[i + 1] >= ans)
      {
        ans = gcd(x[i + 1], ans);
      }
      else
      {
        ans = gcd(ans, x[i + 1]);
      }
    }
  }

  cout << ans << endl;
}
