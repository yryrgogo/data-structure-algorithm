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

// vector<ll> P[100001];

int main()
{
  int N, M;
  cin >> N >> M;
  vector<ll> p(M, -1), y(M, -1);
  vector<vector<ll>> P(N + 1);

  rep(i, M)
  {
    cin >> p[i] >> y[i];
    P[p[i]].push_back(y[i]);
  }

  rep(i, N) sort(P[i + 1].begin(), P[i + 1].end());
  // rep(i, N)
  // {
  //   if (P[i + 1].size() > 0)
  //   {
  //     rep(j, P[i + 1].size())
  //     {
  //       cout << (i + 1) << " " << P[i + 1][j] << " ";
  //     }
  //     cout << endl;
  //   }
  // }

  rep(i, M)
  {
    ll sort_no = int(lower_bound(P[p[i]].begin(), P[p[i]].end(), y[i]) - P[p[i]].begin()) + 1;
    printf("%012lld\n", 1000000 * p[i] + sort_no);
  }
}