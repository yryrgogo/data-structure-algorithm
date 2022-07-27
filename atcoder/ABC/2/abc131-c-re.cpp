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

  ll E = C * D;
  ll G = E / gcd(C, D);

  ll ans = ((B) / C) - ((A - 1) / C);
  ans += ((B) / D) - ((A - 1) / D);
  ans -= ((B) / G) - ((A - 1) / G);

  cout << (B - A + 1) - ans << endl;
}