#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  string S, T;
  cin >> S >> T;

  ll N = S.size();
  ll M = T.size();
  vvll dp(N + 1, vll(M + 1, INF));
  dp[0][0] = 0;

  rep(i, S.size())
  {
    rep(j, T.size())
    {
      dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (S[i] == T[j])
      {
        dp[i + 1][j + 1] = dp[i][j];
      }
      else
      {
        dp[i + 1][j + 1] = dp[i][j] + 1;
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
      }
    }
  }

  pt(dp[N][M]);
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