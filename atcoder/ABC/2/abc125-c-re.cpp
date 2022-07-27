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
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N)
  {
    cin >> A[i];
  }

  ll f[N], b[N];

  f[0] = A[0];
  b[N - 1] = A[N - 1];
  rep(i, N - 1)
  {
    f[i + 1] = gcd(f[i], A[i + 1]);
    b[(N - 1) - (i + 1)] = gcd(b[(N - 1) - i], A[(N - 1) - (i + 1)]);
  }

  ll ans = 0;
  rep(i, N)
  {
    if (i == 0)
    {
      ans = max(b[i + 1], ans);
      continue;
    }
    if (i == N - 1)
    {
      ans = max(f[i - 1], ans);
      continue;
    }

    // printf("%lld : %lld : %lld\n", i, f[i - 1], b[i + 1]);

    ans = max(ans, gcd(f[i - 1], b[i + 1]));
  }

  cout << ans << endl;
}