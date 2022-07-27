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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &alpha, const vector<long long> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  ll N, M;
  cin >> N >> M;
  vll a(M);
  rep(i, M) cin >> a[i];
  sort(a.begin(), a.end());

  vll dp(N + 1);
  dp[0] = 1;

  repd(i, 1, N + 1)
  {
    int is_lack = binary_search(a.begin(), a.end(), i);

    if (is_lack)
    {
      dp[i] = 0;
      continue;
    }

    if (i == 1)
    {
      dp[i] = dp[i - 1];
    }
    else
    {
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
  }

  cout << dp[N] << endl;
}