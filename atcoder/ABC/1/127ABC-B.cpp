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

int calc(int r, int x, int D)
{
  return r * x - D;
}

int main()
{
  int r, D, x2;
  cin >> r >> D >> x2;

  int x = x2;
  rep(i, 10)
  {
    x = calc(r, x, D);
    cout << x << endl;
  }
}