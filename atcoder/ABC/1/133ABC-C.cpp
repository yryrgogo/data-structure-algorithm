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
  ll L, R;
  cin >> L >> R;

  ll N = (R - L + 1) > 2020 ? 2020 : (R - L + 1);
  vll I(N);

  repd(i, L, R + 1)
  {
    if ((i - L) == N)
      break;
    I[i - L] = i % 2019;
  }

  ll ans = INF;
  rep(i, I.size())
  {
    rep(j, I.size())
    {
      // printf("%lld : %lld : %lld \n", I[i], I[j], ans);
      if (I[i] == I[j])
        continue;
      ans = min((I[i] * I[j]) % 2019, ans);
      // printf("%lld : %lld : %lld \n", I[i], I[j], ans);
    }
  }

  cout << ans << endl;
}