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

ll N;
int ans = 0;

bool isOk(ll num)
{
  bool is7 = false;
  bool is5 = false;
  bool is3 = false;

  for (auto s : to_string(num))
  {
    if (s == '7')
      is7 = true;
    if (s == '5')
      is5 = true;
    if (s == '3')
      is3 = true;
  }

  return is7 && is5 && is3;
}

int dfs(int depth, ll num)
{
  if (depth == 10)
  {
    return 0;
  }

  if (N >= num and isOk(num))
    ans++;

  dfs(depth + 1, num * 10 + 3);
  dfs(depth + 1, num * 10 + 5);
  dfs(depth + 1, num * 10 + 7);

  return ans;
}

int main()
{
  cin >> N;

  dfs(0, 0);

  cout << ans << endl;
}