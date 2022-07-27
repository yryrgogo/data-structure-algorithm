#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> p(N);
  rep(i, N)
  {
    ll a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  msort(p, 1);
  msort(p, 0);

  rep(i, N)
  {
    rep(j, N)
    {
      rep(k, N)
      {
        if (i == j || i == k || j == k)
          continue;

        double a;
        double b;
        if (p[j][0] - p[i][0] == 0)
        {
          a = 0;
          b = p[i][1] - a * p[i][0];
        }
        else
        {
          a = (p[j][1] - p[i][1]) / (p[j][0] - p[i][0]);
          b = p[i][1] - a * p[i][0];
        }

        if ((a * p[k][0] + b) == (p[k][1]))
        {
          pt("Yes");
          return 0;
        }
      }
    }
  }
  pt("No");

  return 0;
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

/*
input: 整数T n
output: vector<T> nの素因数分解結果（約数列挙）
*/
template <typename T>
vector<T> prime_factor(T n)
{
  vector<T> ret;
  for (T i = 2; i * i <= n; i++)
  {
    T tmp = 0; // 割り切れる回数
    while (n % i == 0)
    {
      tmp++;
      n /= i;
    }
    if (tmp > 0)
      for (T j = 0; j < tmp; j++)
      {
        ret.push_back(i);
      }
  }
  if (n != 1)
    ret.push_back(n);
  return ret;
}

#endif