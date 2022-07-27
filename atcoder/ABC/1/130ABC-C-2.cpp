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

int main()
{

  double W, H, x, y;
  cin >> W >> H >> x >> y;

  printf("%.12f", (W / 2) * H);
  // center
  if (x == (W / 2) && y == (H / 2))
    cout << " 1" << endl;
  // not center
  else
    cout << " 0" << endl;
}