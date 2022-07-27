#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N, x;
  cin >> N >> x;
  ll a[N];
  rep(i, N) cin >> a[i];

  ll ans = 0;

  repd(i, 1, N)
  {
    ll d1 = (a[i] + a[i - 1]) - x;
    // ll d2 = (a[i] + a[i + 1]) - x;

    if (d1 > 0)
    {
      ans += d1;
      if (a[i] - d1 < 0)
      {
        a[i - 1] -= (d1 - a[i]);
        a[i] = 0;
      }
      else
      {
        a[i] -= d1;
      }
    }
  }

  pt(ans);
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