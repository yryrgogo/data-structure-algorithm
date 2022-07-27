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

int gcd(int x, int y)
{
  if (y == 0)
    return x;
 return gcd(y, x % y);
}

int main()
{
  int N;
  cin >> N;
  int A[N];

  rep(i, N) cin >> A[i];

  int ans;
  rep(i, N)
  {
    if (i == 0)
      ans = gcd(A[i + 1], A[i]);
    else
      ans = gcd(ans, A[i]);
  }

  cout << ans << endl;
}