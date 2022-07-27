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

  int length = 0;
  int ans = 0;

  rep(i, S.size())
  {
    if ((S[i] == 'A') || (S[i] == 'C') || (S[i] == 'G') || (S[i] == 'T'))
    {
      length++;
    }
    else
    {
      if (ans < length)
      {
        ans = length;
      }
      length = 0;
    }
  }

  if (ans < length)
  {
    ans = length;
  }

  cout << ans << endl;
}