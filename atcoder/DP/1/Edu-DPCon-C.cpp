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
const ll ZERO = 0;

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

int N;
ll dp[100010][3];
ll a[100010][3];
ll ans = 0;

int main()
{
  int N;
  cin >> N;
  rep(i, N)
  {
    rep(j, 3)
    {
      cin >> a[i + 1][j];
    }
  }

  rep(i, N)
  {
    rep(j, 3)
    {
      rep(k, 3)
      {
        if (j == k)
          continue;
        chmax(dp[i + 1][k], dp[i][j] + a[i + 1][k]);
      }
    }
  }

  ll res = 0;
  rep(j, 3) chmax(res, dp[N][j]);
  cout << res << endl;
}