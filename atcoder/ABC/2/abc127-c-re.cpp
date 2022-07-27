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
  int N, M;
  cin >> N >> M;
  vi L(M), R(M);

  rep(i, M)
  {
    cin >> L[i] >> R[i];
  }

  int max_l = *max_element(L.begin(), L.end());
  int min_r = *min_element(R.begin(), R.end());

  int ans = min_r - max_l + 1;

  if (ans >= 0)
    cout << ans << endl;
  else
    cout << 0 << endl;
}