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

  int N;
  cin >> N;
  int x[N], y[N];
  rep(i, N) cin >> x[i] >> y[i];

  double ans = 0;
  rep(i, N)
  {
    repd(j, i, N)
    {
      double dist = sqrt((double)pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
      if (ans < dist)
      {
        ans = dist;
      }
    }
  }

  printf("%.12f", ans);
}