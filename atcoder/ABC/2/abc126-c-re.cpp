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
  ll N, K;
  cin >> N >> K;

  double ans = 0;
  rep(i, N)
  {
    ll n = i + 1;
    if (n < K)
    {
      ll cnt = ceil(log2((double)K / n));
      double p = 1 / pow(2, cnt) * (1 / (double)N);
      // cout << n << ":" << cnt << ":" << p << endl;
      ans += p;
    }
    else
    {
      ans += (1 / (double)N);
    }
  }
  printf("%.12f", ans);
}