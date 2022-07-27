// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{

  ll N, W;
  cin >> N >> W;
  ll w[N], v[N];
  ll INF = 1000000007;
  ll dp[N + 10][1001 * N] = {INF};

  rep(i, N)
  {
    cin >> w[i] >> v[i];
  };
  rep(i, N + 10)
  {
    rep(j, 1001 * N)
    {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;

  rep(i, N)
  {
    rep(sum_p, 1000 * N + 1)
    {
      if (sum_p - v[i] >= 0)
      {
        chmin(dp[i + 1][sum_p], dp[i][sum_p - v[i]] + w[i]);
      }
      chmin(dp[i + 1][sum_p], dp[i][sum_p]);
    }
  }

  ll ans = 0;
  rep(sum_p, 1000 * N + 1)
  {
    if (dp[N][sum_p] <= W)
    {
      if (sum_p > ans)
      {
        ans = sum_p;
      }
    }
  }
  cout << ans << endl;
}
