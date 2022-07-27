#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
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
  ll N;
  cin >> N;

  ll h[N];
  rep(i, N) cin >> h[i];

  ll dp[N];
  rep(i, N) dp[i] = INF;
  dp[0] = 0;

  repd(i, 0, N)
  {
    chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }
  cout << dp[N - 1];
}
