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

int main()
{
  int N;
  cin >> N;
  int h[N];
  int A[N];
  int g[N][N];
  int a, x;
  rep(i, N) rep(j, N) g[i][j] = -1;

  rep(i, N)
  {
    h[i] = 0;
    cin >> A[i];
    rep(j, A[i])
    {
      cin >> a >> x;
      --a;
      g[i][a] = x;
    }
  }

  int ans = 0;
  rep(i, 1 << N)
  {
    vector<int> d(N);
    rep(j, N)
    {
      if (i >> j & 1)
      {
        d[j] = 1;
      }
    }

    bool ok = true;

    rep(j, N)
    {
      if (d[j])
      {
        rep(k, N)
        {
          if (g[j][k] == -1)
            continue;
          if (g[j][k] != d[k])
            ok = false;
        }
      }
    }

    if (ok)
      ans = max(ans, __builtin_popcount(i));
  }

  cout << ans << endl;
}