// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int N, M;
int k[11];
int p[11];
int ans = 0;
int s[11][11] = {0};

int check(int sws[11])
{
  int on = 0;
  rep(i, M)
  {
    int cnt = 0;
    rep(j, k[i])
    {
      int idx = s[i][j] - 1;
      cnt += sws[idx];
    }
    if (cnt % 2 == p[i])
    {
      on++;
    }
  }

  return on == M ? 1 : 0;
}

void dfs(int depth, int sws[11])
{
  if (depth == 0)
  {
    ans += check(sws);
    return;
  }

  rep(i, 2)
  {
    sws[depth - 1] = i;
    dfs(depth - 1, sws);
  }

  return;
}

int main()
{
  cin >> N >> M;
  rep(i, M)
  {
    cin >> k[i];
    rep(j, k[i]) cin >> s[i][j];
  }
  rep(i, M) cin >> p[i];

  int sws[N] = {0};
  dfs(N, sws);

  cout << ans << endl;
}