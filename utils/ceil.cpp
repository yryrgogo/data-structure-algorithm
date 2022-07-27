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

  rep(i, 50)
  {
    // 1-10 を10にならす。11-20は20
    printf("%d :%d\n", i, (i + 9) / 10 * 10);
    // 0-9 を次の10の倍数に切り上げ
    printf("%d :%d\n", i, (i + 10) / 10 * 10);
  }
}