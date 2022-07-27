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
  int H[N];
  rep(i, N) cin >> H[i];

  int ans = 1;

  repd(i, 1, N)
  {
    bool is_high = true;
    repd(j, 0, i)
    {
      if (H[i] >= H[j])
      {
        continue;
      }
      else
      {
        is_high = false;
        break;
      }
    }

    if (is_high)
    {
      ans++;
    }
  }

  cout << ans << endl;
}