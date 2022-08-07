#if !__INCLUDE_LEVEL__

#include __FILE__

ll N;
vector<string> ans;

int main()
{
  cin >> N;

  if (N % 2 == 1)
  {
    return 0;
  }

  rep(i, 1 << N)
  {
    if ((i >> (N - 1) & 1) && !(i & 1) && __builtin_popcount(i) == N / 2)
    {
      string s = "";
      rep(j, N)
      {
        if (i >> j & 1)
        {
          s = "(" + s;
        }
        else
        {
          s = ")" + s;
        }
      }

      bool ok = true;
      int left = 0;
      int right = 0;
      rep(j, s.size())
      {
        if (s[j] == '(')
        {
          left++;
        }
        else
        {
          right++;
        }
        if (left < right)
        {
          ok = false;
        }
      }
      if (ok)
      {
        ans.push_back(s);
      }
    }
  }

  sort(ans.begin(), ans.end());
  rep(i, ans.size())
  {
    pt(ans[i]);
  }
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