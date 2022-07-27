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

int N, W;
ll w[100010];
ll v[100010];
ll dp[107][107][2];

void rec(depth)
{

  if (depth == 0)
    return;

  rep(i, 2)
  {
    if (i)
    {
      dp[depth+1][0] += dp[depth][0] + w[depth];
      dp[depth+1][1] += dp[depth][1] + v[depth];
    }
    rec(depth - 1);
  }
}

int main()
{

  cin >> N >> W;
  rep(i, N) cin >> w[i] >> v[i];

  rec();
}