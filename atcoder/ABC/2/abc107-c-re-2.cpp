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
  vector<int> x;

  rep(i, N)
  {
    int y;
    cin >> y;
    x.push_back(y);
  }

  sort(x.begin(), x.end());

  ll ans = INF;

  rep(i, N - (K - 1))
  {
    ll tmp = 0;
    if (x[i] >= 0 && x[i + K - 1] >= 0)
    {
      tmp = abs(x[i + K - 1]);
    }
    else if (x[i] < 0 && x[i + K - 1] >= 0)
    {
      tmp = abs(x[i]) * 2 + abs(x[i + K - 1]);
    }
    else
    {
      tmp = INF;
    }

    ans = min(ans, tmp);

    tmp = 0;
    if (x[i] < 0 && x[i + K - 1] >= 0)
    {
      tmp = abs(x[i]) + abs(x[i + K - 1]) * 2;
    }
    else if (x[i] < 0 && x[i + K - 1] <= 0)
    {
      tmp = abs(x[i]);
    }
    else
    {
      tmp = INF;
    }

    ans = min(ans, tmp);
  }

  cout << ans << endl;
}