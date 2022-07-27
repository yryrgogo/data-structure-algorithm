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

ll gcd(ll x, ll y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int main()
{

  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll cnt = B - A + 1;

  // Cで割り切れる
  // 全体
  ll bdc = B / C;

  // A未満
  ll adc = (A - 1) / C;

  // Dで割り切れる
  // 全体
  ll bdd = B / D;

  // A未満
  ll add = (A - 1) / D;

  // CでもDでも割り切れる
  ll g = gcd(C, D);
  ll l = C * D / g;

  // 全体
  ll bdcd = B / l;

  // A未満
  ll adcd = (A - 1) / l;

  cout << cnt - (bdc - adc) - (bdd - add) + (bdcd - adcd);
}