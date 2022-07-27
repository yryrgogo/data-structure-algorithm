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
  string S;
  cin >> S;
  vll even(2, 0);
  vll odd(2, 0);
  rep(i, S.size())
  {
    if (i % 2 == 0)
    {
      even[S[i] - '0']++;
    }
    else
    {
      odd[S[i] - '0']++;
    }
  }

  ll ans = INF;
  ans = min(even[1] + odd[0], ans);
  ans = min(even[0] + odd[1], ans);

  cout << ans << endl;
}