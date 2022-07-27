#include <bits/stdc++.h>
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

int main()
{

  double W, H, X, Y;
  cin >> W >> H >> X >> Y;

  double xs, ys;

  printf("%.12f", W * H / 2);
  char same = W / 2 == X & H / 2 == Y ? '1' : '0';
  cout << " " << same;
}