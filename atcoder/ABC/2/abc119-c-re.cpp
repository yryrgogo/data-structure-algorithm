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

int N, A, B, C;
ll ans = INF;
int GROUP = 3;
vector<int> l;

ll synthetic(vector<int> values, int L)
{
  ll cost = 10 * (values.size() - 1);
  cost += abs(L - accumulate(values.begin(), values.end(), 0));

  return cost;
}

ll score(string S)
{
  ll result = INF;

  rep(i, 1 << N)
  {
    vector<vector<int>> v(GROUP);

    rep(j, N)
    {
      if (i >> j & 1)
      {
        v[S[j] - '0'].push_back(l[j]);
      }
    }

    bool ok = true;
    rep(g, GROUP)
    {
      if (v[g].size() < 1)
        ok = false;
    }

    vector<int> D = {A, B, C};

    if (ok)
    {
      ll mp = 0;
      rep(g, GROUP)
      {
        mp += synthetic(v[g], D[g]);
      }

      result = min(result, mp);
    }
  }

  return result;
}

void dfs(int depth, string S)
{
  if (depth == 0)
  {
    // cout << S << endl;
    ans = min(score(S), ans);
    return;
  }

  rep(g, GROUP)
  {
    dfs(depth - 1, S + to_string(g));
  }
}

int main()
{
  cin >> N >> A >> B >> C;
  rep(i, N)
  {
    int v;
    cin >> v;
    l.push_back(v);
  }

  string S = "";

  dfs(N, S);

  cout << ans << endl;
}