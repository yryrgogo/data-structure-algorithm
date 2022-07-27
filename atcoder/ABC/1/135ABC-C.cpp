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

int main()
{
  ll N;
  cin >> N;
  ll A[N + 1], B[N];
  rep(i, N + 1) cin >> A[i];
  rep(i, N) cin >> B[i];

  ll ans = 0;
  rep(i, N)
  {
    ll power = B[i] - A[i];
    if (power > 0)
    {
      ans += A[i];
      ll level = max((ll)0, A[i + 1] - power);
      if (level == 0)
      {
        ans += A[i + 1];
      }
      else
      {
        ans += power;
      }
      A[i + 1] = level;
    }
    else
    {
      ans += B[i];
    }
  }
  cout << ans << endl;
}