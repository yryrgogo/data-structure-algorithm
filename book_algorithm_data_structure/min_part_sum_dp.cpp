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

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

int main()
{
  int N, W;
  cin >> N >> W;

  vector<int> value(N);
  rep(i, N)
  {
    cin >> value[i];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, INF));
  dp[0][0] = 0;

  rep(i, N)
  {
    rep(w, W + 1)
    {
      if (w - value[i] >= 0)
      {
        chmin(dp[i + 1][w], dp[i][w - value[i]] + 1);
      }
      chmin(dp[i + 1][w], dp[i][w]);
    }
  }

  cout << dp[N][W] << endl;
}
