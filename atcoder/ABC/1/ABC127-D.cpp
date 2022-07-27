#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N, M;
  cin >> N >> M;
  vll A(N);
  map<ll, ll, greater<ll>> mp;

  rep(i, N) cin >> A[i];
  rep(i, M)
  {
    ll B, C;
    cin >> B >> C;
    mp[C] += B;
  }

  sort(A.begin(), A.end());
  ll minV = A[0];
  ll idx = 0;
  ll ans = 0;

  for (auto p : mp)
  {
    if (p.first > minV)
    {
      // 入れ替え候補の値 p.first 以下の値の個数がわかる（同値の場合は1個までしか数えないが）
      ll dist = distance(A.begin() + idx, upper_bound(A.begin() + idx, A.end(), p.first));
      // printf("%lld : %lld : %lld\n", p.first, dist, minV);
      if (p.second >= dist)
      {
        idx += dist;
        minV = A[idx];
        ans += dist * p.first;
      }
      else
      {
        idx += p.second;
        minV = A[idx];
        ans += p.second * p.first;
      }
    }
  }

  ans = accumulate(A.begin() + idx, A.end(), ans);

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