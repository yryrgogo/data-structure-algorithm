#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &alpha, const vector<long long> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  ll N;
  cin >> N;
  map<string, ll> mp;

  ll mv = 0;
  rep(i, N)
  {
    string s;
    cin >> s;
    mp[s]++;
    if (mv < mp[s])
    {
      mv = mp[s];
    }
  }

  for (auto &p : mp)
  {
    if (p.second == mv)
    {
      cout << p.first << endl;
    }
  }
}