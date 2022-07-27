#if !__INCLUDE_LEVEL__

#include __FILE__

map<char, int> exist(string s, map<char, int> mp)
{
  unordered_map<char, int> mp1;
  map<char, int> mp2;
  for (auto c : s)
  {
    mp1[c]++;
  }

  for (auto p : mp1)
  {
    if (mp[p.first] > 0)
    {
      mp2[p.first] = min(mp[p.first], p.second);
    }
  }

  return mp2;
}

int main()
{
  int N;
  cin >> N;
  string S[N];
  rep(i, N) cin >> S[i];

  if (N == 1)
  {
    string s = S[0];
    sort(s.begin(), s.end());
    pt(s);
    return 0;
  }

  map<char, int> mp;
  unordered_map<char, int> mp1;
  unordered_map<char, int> mp2;
  for (auto c : S[0])
    mp1[c]++;
  for (auto c : S[1])
    mp2[c]++;

  for (auto p : mp1)
  {
    if (mp2[p.first] > 0)
    {
      mp[p.first] = min(p.second, mp2[p.first]);
    }
  }

  repd(i, 2, N)
  {
    mp = exist(S[i], mp);
  }

  string ans = "";
  for (auto p : mp)
  {
    rep(i, p.second)
    {
      ans += p.first;
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