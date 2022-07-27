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

int main()
{
  int N, W;
  cin >> N >> W;
  vector<pair<ll, ll>> vp(N);
  rep(i, N) cin >> vp[i].first >> vp[i].second;

  vector<bool> dv(N, false);
  vector<pair<ll, vector<bool>>> dp(W + 1, make_pair(0, dv));

  repd(w, 1, W + 1)
  {
    rep(i, N)
    {
      if (w - vp[i].first >= 0)
      {
        if (dp[w - vp[i].first].second[i] == false)
        {
          if (chmax(dp[w].first, dp[w - vp[i].first].first + vp[i].second))
          {
            dp[w].second = dp[w - vp[i].first].second;
            dp[w].second[i] = true;
          }
        }
      }
    }
    if (chmax(dp[w].first, dp[w - 1].first))
    {
      dp[w].second = dp[w - 1].second;
    }
  }

  cout << dp[W].first << endl;
}