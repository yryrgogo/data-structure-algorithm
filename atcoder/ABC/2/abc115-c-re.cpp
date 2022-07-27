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
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<ll> h(N);
  rep(i, N)
  {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  ll ans = INF;
  rep(i, N - K + 1)
  {
    ll diff = h[i + K - 1] - h[i];
    if (ans > diff)
      ans = diff;
  }

  cout << ans << endl;
}