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

int N;
int p[110];
int dp[110][10010] = {0};

int main()
{

  cin >> N;
  repd(i, 1, N + 1) cin >> p[i];

  dp[0][0] = 1;
  rep(i, 100)
  {
    repd(sum_p, 0, 10000 + 1)
    {
      if (dp[i][sum_p])
      {
        dp[i + 1][sum_p + p[i + 1]] = 1;
      }
      else if (sum_p == p[i + 1])
      {
        dp[i + 1][sum_p] = 1;
      }
      chmax(dp[i + 1][sum_p], dp[i][sum_p]);
    }
  }

  int ans = 0;
  rep(i, 10001)
  {
    ans += dp[100][i];
  }
  cout << ans << endl;
}