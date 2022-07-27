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

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

int N;
vector<ll> h;
vector<ll> dp;

ll rec(int i)
{
  if (dp[i] < INF)
    return dp[i];

  if (i == 0)
    return 0;

  ll res = INF;

  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

  if (i > 1)
    chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

  return dp[i] = res;
}

int main()
{
  cin >> N;
  h.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> h[i];

  dp.assign(N, INF);

  cout << rec(N - 1) << endl;
}