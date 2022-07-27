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
  int N, W, K;
  cin >> N >> W >> K;

  vector<int> value(N);
  rep(i, N)
  {
    cin >> value[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  dp[0][0] = 1;

  rep(i, N)
  {
    rep(w, W + 1)
    {
      // これまで選択された品数が K 未満だったら追加 OK
      if (w - value[i] >= 0 && dp[i][w - value[i]] < K)
      {
        dp[i + 1][w] += dp[i][w - value[i]];
      }
      dp[i + 1][w] += dp[i][w];
    }
  }

  cout << dp[N][W] << endl;
}