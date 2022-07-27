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
  ll H[N];
  rep(i, N) cin >> H[i];

  string ans = "Yes";
  ll high = H[0];

  rep(i, N)
  {
    // if (H[i] - H[i + 1] >= 2)
    // {
    //   ans = "No";
    // }
    // else if (H[i] - H[i + 1] == 1)
    // {
    //   H[i + 1] -= 1;
    // }

    if (high - 1 > H[i])
    {
      ans = "No";
    }

    if (high < H[i])
    {
      high = H[i];
    }
  }

  cout << ans << endl;
}