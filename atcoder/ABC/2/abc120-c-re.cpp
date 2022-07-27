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
  string S;
  cin >> S;

  int cnt = 0;
  int ans = 0;
  char pre;

  while (cnt + 1 < S.size())
  {
    if (S[cnt] != S[cnt + 1])
    {
      string s = "";
      if (cnt > 0)
      {
        s = S.substr(0, cnt);
      }
      if (S.size() - (cnt + 2) > 0)
      {
        s += S.substr(cnt + 2, S.size() - (cnt + 2));
      }

      // cout << cnt << ':' << S << ':' << s << endl;

      ans += 2;
      cnt = 0;
      S = s;
      continue;
    }

    cnt++;
  }

  cout << ans;
}