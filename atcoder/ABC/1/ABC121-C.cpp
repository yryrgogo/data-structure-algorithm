// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;

int main()
{

  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> v;
  rep(i, N)
  {
    ll a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  ll cnt = 0;
  rep(i, N)
  {
    if (M > cnt)
    {
      ans += min(v[i].second, M - cnt) * v[i].first;
      cnt += min(v[i].second, M - cnt);
    }
  }
  cout << ans;
}