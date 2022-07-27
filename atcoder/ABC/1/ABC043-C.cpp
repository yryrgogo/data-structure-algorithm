#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N;
  cin >> N;
  vll a(N);
  int cnt = 0;
  double avg;
  rep(i, N)
  {
    cin >> a[i];
    avg += a[i];
    if (i > 0)
    {
      if (a[i - 1] == a[i])
        cnt++;
    }
  }
  avg = round(avg / N);

  if (N == cnt + 1)
  {
    pt(0);
    return 0;
  }

  ll cost = INF;
  ll ans = 0;
  // repd(i, -100, 101)
  // {
  ll tmp = 0;
  rep(j, N)
  {
    tmp += pow(avg - a[j], 2);
  }
  if (cost > tmp)
  {
    cost = tmp;
    // ans = i;
  }
  // }

  pt(cost);
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