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
void chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
  }
}

int main()
{
  int N, W;
  cin >> N >> W;

  int a[N];
  rep(i, N)
  {
    cin >> a[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  rep(i, N)
  {
    rep(w, W + 1)
    {
      if (w - a[i] >= 0)
      {
        chmax(dp[i + 1][w], dp[i][w - a[i]] + a[i]);
      }

      // chmax(dp[i + 1][w], dp[i][w]);

      // if (i == N - 1 && W - 1 > 0)
      if (i == N - 1)
      {
        cout << dp[N - 1][w] << endl;
      }
    }
  }

  rep(w, W + 1)
  {
    cout << dp[5][w] << endl;
  }

  // cout << dp[N][W] << endl;
}