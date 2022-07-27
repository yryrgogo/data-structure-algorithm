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

bool is_light_up(vi k, vi p, vvi s, vi S)
{
  bool ok = true;
  rep(i, s.size())
  {
    int cnt = 0;
    for (auto sw : s[i])
    {
      if (S[sw - 1])
      {
        cnt++;
      }
    }
    // cout << cnt % 2 << ":" << p[i] << endl;
    if (cnt % 2 != p[i])
    {
      ok = false;
    }
  }
  // cout << "---" << endl;

  return ok;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vi k(M), p(M);
  vvi s(M);

  rep(i, M)
  {
    cin >> k[i];
    rep(j, k[i])
    {
      int sw;
      cin >> sw;
      s[i].push_back(sw);
    }
  }
  rep(i, M) cin >> p[i];

  int ans = 0;
  rep(i, 1 << N)
  {
    vi S(N, 0);
    rep(j, N)
    {
      if ((i >> j) & 1)
      {
        S[j] = 1;
      }
    }

    bool is_all = is_light_up(k, p, s, S);
    if (is_all)
      ans++;
  }

  cout << ans << endl;
}