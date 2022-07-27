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
const ll MOD = 1000000007;

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

  ll N, M;
  cin >> N >> M;
  ll a[M];
  ll dp[N + 1] = {0};
  rep(i, M) cin >> a[i];
  dp[0] = 1;

  ll num = 0;

  rep(i, N)
  {
    if (i + 1 == a[num])
    {
      dp[i + 1] = 0;
      num++;
      num = min(num, M - 1);
      continue;
    }

    if (i == 0)
    {
      dp[i + 1] = dp[i] % MOD;
      continue;
    }
    dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
  }

  cout << dp[N] << endl;
}