#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int N;
  cin >> N;
  int A[N];
  int x[N][15], y[N][15];
  rep(i, N)
  {
    cin >> A[i];
    rep(j, A[i]) cin >> x[i][j] >> y[i][j];
  }

  int ans = 0;
  rep(i, 1 << N)
  {
    int a[15];
    rep(j, N)
    {
      if (i >> j & 1)
        a[j] = 1;
      else
        a[j] = 0;
    }

    bool ok = true;
    rep(j, N)
    {
      if (a[j] == 0)
        continue;

      rep(k, A[j])
      {
        if (a[x[j][k] - 1] != y[j][k])
        {
          ok = false;
          break;
        }
      }
      if (!ok)
        break;
    }

    if (ok)
    {
      ans = max(ans, __builtin_popcount(i));
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