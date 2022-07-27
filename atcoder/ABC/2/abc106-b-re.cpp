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
  int N;
  cin >> N;
  int ans = 0;

  if (N < 105)
  {
    cout << 0 << endl;
  }
  else
  {
    repd(i, 105, N + 1)
    {
      if (i % 2 == 0)
      {
        continue;
      }

      int cnt = 2;

      repd(j, 2, i / 2)
      {
        if (i % j == 0)
        {
          cnt++;
        }
      }

      if (cnt == 8)
      {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
