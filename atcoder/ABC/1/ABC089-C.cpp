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

  string s = "MARCH";
  int c[5] = {0};
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    string t;
    cin >> t;
    for (int j = 0; j < 5; j++)
    {
      if (t[0] == s[j])
      {
        c[j]++;
      }
    }
  }

  ll ans = 0;
  repd(i, 0, 5)
  {
    repd(j, i + 1, 5)
    {
      repd(k, j + 1, 5)
      {
        ans += c[i] * c[j] * c[k];
      }
    }
  }
  cout << ans << endl;

  // ll N;
  // cin >> N;
  // vector<char> S;
  // unordered_map<char, ll> mp;

  // rep(i, N)
  // {
  //   string s;
  //   cin >> s;
  //   if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
  //   {
  //     // S.push_back(s[0]);
  //     mp[s[0]]++;
  //   }
  // }

  // ll ans = 0;
  // map<vector<char>, int> m;
  // for (auto x : mp)
  // {
  //   for (auto y : mp)
  //   {
  //     for (auto z : mp)
  //     {
  //       if (x.first != y.first && x.first != z.first && y.first != z.first)
  //       {
  //         vector<char> c;
  //         c.push_back(x.first);
  //         c.push_back(y.first);
  //         c.push_back(z.first);
  //         sort(c.begin(), c.end());

  //         if (m[c] == 0)
  //         {
  //           m[c]++;
  //           ans += x.second * y.second * z.second;
  //         }
  //       }
  //     }
  //   }
  // }

  // cout << ans << endl;
}