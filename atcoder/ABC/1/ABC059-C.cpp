#if !__INCLUDE_LEVEL__

#include __FILE__

void pl(ll &ans, ll &sum)
{
  if (sum <= 0)
  {
    ll diff = (1 - sum);
    ans += abs(diff);
    sum += diff;
  }
}

void mi(ll &ans, ll &sum)
{
  if (sum >= 0)
  {
    ll diff = (-1 - sum);
    ans += abs(diff);
    sum += diff;
  }
}

int main()
{
  ll N;
  cin >> N;
  vll a(N);
  rep(i, N) cin >> a[i];

  // plus start ver
  ll ans1 = 0;
  ll ans2 = 0;
  ll sum;
  ll cnt;

  cnt = 0;
  sum = 0;
  rep(i, N)
  {
    cnt++;
    sum = sum + a[i];

    if (cnt % 2 == 1)
    {
      pl(ans1, sum);
    }
    else
    {
      mi(ans1, sum);
    }
  }

  // minus start ver
  cnt = 0;
  sum = 0;
  rep(i, N)
  {
    cnt++;
    sum = sum + a[i];

    if (cnt % 2 == 0)
    {
      pl(ans2, sum);
    }
    else
    {
      mi(ans2, sum);
    }
  }

  pt(min(ans1, ans2));
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