#if !__INCLUDE_LEVEL__

#include __FILE__

ll N, L, K;
vll A;

bool solve(ll mid)
{
  int cnt = 0;
  ll pre = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] - pre >= mid && L - A[i] >= mid)
    {
      cnt++;
      pre = A[i];
    }
  }

  if (cnt >= K)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  cin >> N >> L >> K;
  rep(i, N)
  {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  ll left = -1;
  ll right = L + 1;

  while (right - left > 1)
  {
    ll mid = left + (right - left) / 2;
    if (solve(mid))
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
  }

  pt(left);
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