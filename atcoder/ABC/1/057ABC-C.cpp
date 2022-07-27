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

int get_divisers(ll N)
{
  int n = sqrt(N);

  int j = 0;
  for (int i = n; i >= 1; i--)
  {
    if (N % i == 0)
    {
      j = N / i;
      break;
    }
  }

  return j;
}

int main()
{
  ll N;
  cin >> N;

  int d = get_divisers(N);
  int ans = log10(d) + 1;
  cout << ans << endl;
}