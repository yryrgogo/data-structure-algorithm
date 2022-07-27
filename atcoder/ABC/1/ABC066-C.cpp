#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll n;
  cin >> n;
  ll a[n];

  rep(i, n) cin >> a[i];

  vll front;
  vll ans;
  ll start = 1;
  deque<ll> dq;

  if (n % 2 == 1)
  {
    // front.push_back(a[0]);
    dq.push_front(a[0]);
    start = 2;
  }

  for (int i = start; i < n; i += 2)
  {
    // ans.push_back(a[i - 1]);
    // auto it = ans.begin();
    // ans.insert(it, a[i]);
    // front.push_back(a[i]);

    dq.push_front(a[i]);
    dq.push_back(a[i - 1]);
  }

  // reverse(front.rbegin(), front.rend());

  rep(i, dq.size())
  {
    printf("%lld ", dq[i]);
  }

  // rep(i, front.size())
  // {
  //   printf("%lld ", front[i]);
  // }
  // rep(i, ans.size())
  // {
  //   printf("%lld ", ans[i]);
  // }
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