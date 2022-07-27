#include <bits/stdc++.h>
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

int N, K;
ll h[100010];
ll dp[100010];

ll rec(int i)
{
  if (dp[i] < INF)
    return dp[i];
  if (i == 0)
    return 0;

  ll res = INF;
  repd(k, 1, K + 1)
  {
    if (i - k < 0)
      continue;
    chmin(res, rec(i - k) + abs(h[i] - h[i - k]));
  }

  return dp[i] = res;
}

int main()
{
  cin >> N >> K;
  rep(i, N) cin >> h[i];
  rep(i, N) dp[i] = INF;

  cout << rec(N - 1) << endl;
}