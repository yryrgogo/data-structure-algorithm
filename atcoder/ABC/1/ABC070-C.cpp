#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int N;
  cin >> N;
  vll T(N);

  rep(i, N) cin >> T[i];

  if (N == 1)
  {
    pt(T[0]);
    return 0;
  }

  ll up = max(T[0], T[1]);
  ll low = min(T[0], T[1]);
  ll x, y;
  x = gcd(up, low);
  y = low * (up / x);

  if (N == 2)
  {
    pt(y);
    return 0;
  }

  repd(i, 2, N)
  {
    // up = max(y, T[i]);
    // low = min(y, T[i]);

    // if (up % low == 0)
    // {
    //   y = up;
    // }
    // else
    // {
    // x = gcd(y, T[i]);
    // y = (y * T[i]) / x;
    // }

    up = max(y, T[i]);
    low = min(y, T[i]);
    x = gcd(y, T[i]);
    y = low * (up / x);
  }
  pt(y);
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