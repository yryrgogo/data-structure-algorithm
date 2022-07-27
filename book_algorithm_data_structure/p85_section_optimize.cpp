#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int N = 4;
  vvll dp(N + 1, vll(N + 1, INF));
  // int c[N][N];
  vvll c = {{3, 5, 4, 8},
            {INF, 2, 4, 5},
            {INF, INF, 1, 5},
            {INF, INF, INF, 2}};
  dp[0][0] = 0;

  rep(i, N)
  {
    repd(j, i + 1, N + 1)
    {
      if (i - 1 >= 0)
      {
        chmin(dp[i][j], dp[i - 1][i] + c[i][j - 1]);
        chmin(dp[i][j], dp[i - 1][j]);
      }
      else
      {
        chmin(dp[i][j], dp[0][0] + c[i][j - 1]);
      }
    }
  }
  pt(dp[N - 1][N]);
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