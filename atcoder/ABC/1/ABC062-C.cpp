#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll H, W;
  cin >> H >> W;

  ll ans = INF;
  repd(h1, 0, H)
  {
    ll h2 = (H - h1) / 2;
    ll h3 = H - h1 - h2;
    ll S1 = h1 * W;
    ll S2 = h2 * W;
    ll S3 = h3 * W;
    ll SMAX = max(max(S1, S2), S3);
    ll SMIN = min(min(S1, S2), S3);
    ans = min(ans, abs(SMAX - SMIN));

    //
    S1 = h1 * W;
    ll w1 = W / 2;
    ll w2 = W - w1;
    S2 = w1 * (H - h1);
    S3 = w2 * (H - h1);
    SMAX = max(max(S1, S2), S3);
    SMIN = min(min(S1, S2), S3);
    ans = min(ans, abs(SMAX - SMIN));
  }

  repd(w1, 0, W)
  {
    ll w2 = (W - w1) / 2;
    ll w3 = W - w1 - w2;
    ll S1 = w1 * H;
    ll S2 = w2 * H;
    ll S3 = w3 * H;
    ll SMAX = max(max(S1, S2), S3);
    ll SMIN = min(min(S1, S2), S3);
    ans = min(ans, abs(SMAX - SMIN));

    //
    S1 = w1 * H;
    ll h1 = H / 2;
    ll h2 = H - h1;
    S2 = h1 * (W - w1);
    S3 = h2 * (W - w1);
    SMAX = max(max(S1, S2), S3);
    SMIN = min(min(S1, S2), S3);
    ans = min(ans, abs(SMAX - SMIN));
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