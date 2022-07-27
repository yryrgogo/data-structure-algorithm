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

int N;
ll h[100010];

ll dp[100010];

ll rec(int i)
{
  // DP値が更新されていたらそのままReturn
  if (dp[i] < INF)
    return dp[i];

  // ベースケース
  if (i == 0)
    return 0;

  // i-1, i-2それぞれ試す
  ll res = INF;
  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));
  if (i > 1)
    chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

  // 結果をメモしながら返す
  return dp[i] = res;
}

int main()
{
  int N;
  cin >> N;
  rep(i, N) cin >> h[i];
  rep(i, N) dp[i] = INF;

  cout << rec(N - 1) << endl;
}