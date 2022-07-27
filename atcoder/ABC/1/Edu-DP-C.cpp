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
  int N;
  cin >> N;
  int a[N], b[N], c[N];
  rep(i, N)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  vvi dp(N, vi(3, 0));

  rep(i, N)
  {
    vi v = {a[i], b[i], c[i]};

    if (i == 0)
    {
      rep(j, 3)
      {
        dp[0][j] = v[j];
      }
      continue;
    }

    rep(j, 3)
    {
      if (j == 0)
      {
        chmax(dp[i][j], dp[i - 1][1] + v[j]);
        chmax(dp[i][j], dp[i - 1][2] + v[j]);
      }
      if (j == 1)
      {
        chmax(dp[i][j], dp[i - 1][0] + v[j]);
        chmax(dp[i][j], dp[i - 1][2] + v[j]);
      }
      if (j == 2)
      {
        chmax(dp[i][j], dp[i - 1][0] + v[j]);
        chmax(dp[i][j], dp[i - 1][1] + v[j]);
      }
    }
  }

  int ans = 0;
  rep(i, 3)
  {
    if (dp[N - 1][i] > ans)
    {
      ans = dp[N - 1][i];
    }
  }

  cout << ans << endl;
}