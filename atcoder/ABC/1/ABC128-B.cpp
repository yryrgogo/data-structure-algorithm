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

int main()
{
  int N;
  cin >> N;
  map<string, map<int, int>> mp;
  map<string, vi> mpv;
  rep(i, N)
  {
    string s;
    int p;
    cin >> s >> p;
    mp[s][p * -1] = i + 1;
    // mpv[s].push_back(-1 * p);
  }
  for (auto p : mp)
  {
    for (auto v : p.second)
    {
      cout << v.second << endl;
    }
    // sort(mpv[p.first].rbegin(), mpv[p.first].rend());
    // for (auto x : mpv[p.first])
    // {
    //   cout << mp[p.first][x] << endl;
    // }
  }
}