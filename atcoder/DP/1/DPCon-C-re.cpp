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
  cin >> N;

  int a[N], b[N], c[N];

  rep(i, N)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(3, 0));

  rep(i, N)
  {
    chmax(dp[i + 1][0], dp[i][1] + a[i]);
    chmax(dp[i + 1][0], dp[i][2] + a[i]);

    chmax(dp[i + 1][1], dp[i][0] + b[i]);
    chmax(dp[i + 1][1], dp[i][2] + b[i]);

    chmax(dp[i + 1][2], dp[i][0] + c[i]);
    chmax(dp[i + 1][2], dp[i][1] + c[i]);
  }

  cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;
}