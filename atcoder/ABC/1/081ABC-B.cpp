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

  bool ans;
  rep(i, 9)
  {
    if (N % (i + 1) == 0)
    {
      int a = N / (i + 1);
      if (a < 10 && a > 0)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}