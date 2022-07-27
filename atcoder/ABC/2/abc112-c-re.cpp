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

ll get_height(ll cx, ll cy, ll x, ll y, ll h)
{
  return abs(cx - x) + abs(cy - y) + h;
}

int main()
{
  int N;
  cin >> N;
  ll x[N], y[N], h[N];
  rep(i, N)
  {
    cin >> x[i] >> y[i] >> h[i];
  }

  int MAX = 101;

  rep(i, MAX)
  {
    rep(j, MAX)
    {
      bool ok = true;
      ll H = -1;

      rep(k, N)
      {
        if (h[k] == 0)
        {
          continue;
        }

        if (H == -1)
        {
          H = get_height(i, j, x[k], y[k], h[k]);
        }
        else
        {
          if (H != get_height(i, j, x[k], y[k], h[k]))
          {
            ok = false;
          }
        }
      }

      rep(k, N)
      {
        if (h[k] != 0)
          continue;

        if (get_height(i, j, x[k], y[k], h[k]) < H)
        {
          ok = false;
        }
      }

      if (ok)
      {
        printf("%lld %lld %lld", i, j, H);
        return 0;
      }
    }
  }
}