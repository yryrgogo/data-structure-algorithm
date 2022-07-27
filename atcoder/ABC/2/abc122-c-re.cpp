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
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<int> &alpha, const vector<int> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vi l(Q), r(Q);

  rep(i, Q)
  {
    cin >> l[i] >> r[i];
  }

  rep(i, Q)
  {
    char pre;
    int ans = 0;
    string sub = S.substr((l[i] - 1), (r[i] - l[i] + 1));
    for (auto s : sub)
    {
      if (pre == 'A' && s == 'C')
      {
        ans++;
      }
      pre = s;
    }

    cout << ans << endl;
  }
}