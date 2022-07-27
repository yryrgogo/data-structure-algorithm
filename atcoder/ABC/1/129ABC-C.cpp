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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> broken(n + 1);
  rep(i, m)
  {
    int a;
    cin >> a;
    broken[a] = 1;
  }
  vector<int> dp(n + 1);
  const int mod = 1000000007;
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (broken[i])
    {
      // 壊れている段はルートに入らないので0でcontinue
      dp[i] = 0;
      continue;
    }
    if (i == n - 1)
    {
      dp[i] = (dp[i + 1]) % mod;
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << endl;
  return 0;
}