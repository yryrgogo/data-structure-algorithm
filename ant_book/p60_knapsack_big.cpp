#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int n = 4;
  int W = 5;
  int MAX_V = 10000;
  vi w = {2, 1, 3, 2};
  vi v = {3, 2, 4, 2};

  // ll dp[n + 1][MAX_V + 1];
  vvll dp(n + 1, vll(MAX_V + 1, INF));
  dp[0][0] = 0;

  rep(i, n)
  {
    rep(j, MAX_V + 1)
    {
      if (j - v[i] >= 0 && dp[i][j - v[i]] + w[i] <= W)
      {
        chmin(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
      }
      else
      {
        chmin(dp[i + 1][j], dp[i][j]);
      }
    }
  }

  ll ans = 0;
  rep(j, MAX_V + 1)
  {
    if (dp[n][j] != INF)
    {
      ans = max(ans, j);
    }
  }
  pt(ans);
}

#else

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &a, const vector<long long> &b) { return a[key] < b[key]; })
template <typename T>
void pt(T val)
{
  cout << val << "\n";
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#endif