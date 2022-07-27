// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
#include <cassert>
using namespace std;
using vi = vector<int>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<ll> &alpha, const vector<ll> &beta) { return alpha[key] < beta[key]; });
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

class Shop
{
public:
  int money;
  int stock;

  Shop(int m, int s)
  {
    money = m;
    stock = s;
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> vp(N, (vector<ll>)(2));

  rep(i, N)
  {
    ll a, b;
    cin >> vp[i][0] >> vp[i][1];
  }

  msort(vp, 0);

  // cout << vp[i].first << ":" << vp[i].second << endl;
  ll ans = 0;
  ll cnt = 0;

  rep(i, N)
  {
    if (M >= (cnt + vp[i][1]))
    {
      cnt += vp[i][1];
      ans += vp[i][0] * vp[i][1];
    }
    else if (M - cnt < vp[i][1])
    {
      ans += vp[i][0] * (M - cnt);
      cnt += M - cnt;

      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
}