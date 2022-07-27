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
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  string s;
  cin >> s;
  int K;
  cin >> K;

  int cnt = 1;
  unordered_map<string, int> mp;
  vector<string> v;
  rep(i, s.size())
  {
    for (int j = 1; j < 6; j++)
    {
      if (i + j > s.size())
        continue;
      string sub = s.substr(i, j);
      if (mp[sub] == 0)
      {
        mp[sub]++;
        v.push_back(sub);
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v[K - 1] << endl;
}