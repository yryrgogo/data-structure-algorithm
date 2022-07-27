#if !__INCLUDE_LEVEL__

#include __FILE__

int n = 5;
vll a = {4, 2, 3, 1, 5};
ll dp[5];

void solve()
{
  fill(dp, dp + n, INF);
  rep(i, n)
  {
    *lower_bound(dp, dp + n, a[i]) = a[i];
  }

  pt(lower_bound(dp, dp + n, INF) - dp);
}

int main()
{
  solve();
  // int dp[n];

  // int res = 0;
  // rep(i, n)
  // {
  //   dp[i] = 1;
  //   rep(j, i)
  //   {
  //     if (a[j] < a[i])
  //     {
  //       dp[i] = max(dp[i], dp[j] + 1);
  //     }
  //   }
  //   res = max(res, dp[i]);
  // }

  // pt(res);
}

#else

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using Graph = vector<vector<int>>;
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
template <typename T>
inline ll gcd(T x, T y)
{
  if (y == 0)
  {
    return x;
  }
  return gcd(y, x % y);
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#endif