#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int s[2], t[2];
  cin >> s[0] >> s[1] >> t[0] >> t[1];

  string ans = "";
  rep(i, t[0] - s[0])
      ans += 'R';
  rep(i, t[1] - s[1])
      ans += 'U';
  rep(i, t[0] - s[0])
      ans += 'L';
  rep(i, t[1] - s[1])
      ans += 'D';

  ans += 'D';
  rep(i, 1 + t[0] - s[0])
      ans += 'R';
  rep(i, 1 + t[1] - s[1])
      ans += 'U';
  ans += 'L';

  ans += 'U';
  rep(i, 1 + t[0] - s[0])
      ans += 'L';
  rep(i, 1 + t[1] - s[1])
      ans += 'D';
  ans += 'R';

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