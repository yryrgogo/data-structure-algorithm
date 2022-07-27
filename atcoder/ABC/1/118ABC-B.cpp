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

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> x(M);

  rep(i, N)
  {
    int k;
    cin >> k;
    rep(j, k)
    {
      int l;
      cin >> l;
      x[--l] += 1;
    }
  }

  int ans = 0;

  rep(i, M)
  {
    if (x[i] == N)
    {
      ans++;
    }
  }

  cout << ans << endl;
}