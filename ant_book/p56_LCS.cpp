#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  string s, t;
  cin >> s >> t;

  int N = s.size();
  int M = t.size();

  int dp[N + 1][M + 1];
  rep(i, N + 1) rep(j, M + 1) dp[i][j] = 0;

  rep(i, N)
  {
    rep(j, M)
    {
      if (s[i] == t[j])
      {
        chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      }

      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
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