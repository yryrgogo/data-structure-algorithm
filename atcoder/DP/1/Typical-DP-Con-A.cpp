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
  int p[N];
  int sum = 0;
  rep(i, N)
  {
    cin >> p[i];
    sum += p[i];
  }

  vector<int> v(sum + 1, 0);
  vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));

  rep(i, N)
  {
    rep(s, sum + 1)
    {
      if (s - p[i] >= 0)
      {
        chmax(dp[i + 1][s], dp[i][s - p[i]] + p[i]);
      }
      chmax(dp[i + 1][s], dp[i][s]);
      v[dp[i + 1][s]] = 1;
    }
  }
  int ans = accumulate(v.begin(), v.end(), 0);
  cout << ans << endl;
}