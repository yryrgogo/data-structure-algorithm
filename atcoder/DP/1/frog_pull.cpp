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
  int N;
  cin >> N;
  vector<ll> h(N);
  for (int i = 0; i < N; ++i)
    cin >> h[i];

  vector<ll> dp(N, INF);

  dp[0] = 0;

  for (int i = 1; i < N; ++i)
  {
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    if (i > 1)
      chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[N - 1] << endl;
}
