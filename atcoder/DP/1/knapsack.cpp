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
  int N;
  ll W;
  cin >> N >> W;

  vector<ll> weight(N), value(N);
  for (int i = 0; i < N; ++i)
    cin >> weight[i] >> value[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

  for (int i = 0; i < N; ++i)
  {
    for (int w = 0; w <= W; ++w)
    {
      if (w - weight[i] >= 0)
      {
        chmax(dp[i + 1][w], dp[i][w - weight[i] + value[i]]);
      }

      chmax(dp[i + 1][w], dp[i][w]);
    }
  }

  cout << dp[N][W] << endl;
}