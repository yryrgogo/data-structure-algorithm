#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N;
  cin >> N;

  if (N == 1)
  {
    pt(1);
    return 0;
  }

  vll a(N);
  vll::iterator it;
  rep(i, N) cin >> a[i];
  sort(a.begin(), a.end());

  ll cnt = 1;
  int diff = 0;
  ll sub = 0;
  ll ans = 0;

  rep(i, N - 1)
  {
    it = upper_bound(a.begin(), a.end(), a[i] + 2);
    ll idx = distance(a.begin(), it);
    ans = max(idx - i, ans);
  }
  pt(ans);
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