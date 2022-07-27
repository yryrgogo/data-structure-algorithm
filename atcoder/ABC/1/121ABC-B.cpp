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
  int N, M, C;
  cin >> N >> M >> C;

  int B[M];
  int A[M][N];

  rep(i, M)
  {
    cin >> B[i];
  }

  int ans = 0;
  rep(i, N)
  {
    int sum = C;
    rep(j, M)
    {
      cin >> A[i][j];
      sum += A[i][j] * B[j];
    }
    if (sum > 0)
    {
      ans++;
    }
  }

  cout << ans << endl;
}