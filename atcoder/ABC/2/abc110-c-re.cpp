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
  string S, T;
  cin >> S >> T;
  int x[10000];
  int y[10000];

  rep(i, 10000)
  {
    x[i] = 0;
    y[i] = 0;
  }

  rep(i, S.size())
  {
    if (x[S[i] - '0'] == 0)
    {
      x[S[i] - '0'] = T[i] - '0';
    }
    else if (x[S[i] - '0'] != T[i] - '0')
    {
      // printf("%c\n", S[i]);
      cout << "No" << endl;
      return 0;
    }

    if (y[T[i] - '0'] == 0)
    {
      y[T[i] - '0'] = S[i] - '0';
    }
    else if (y[T[i] - '0'] != S[i] - '0')
    {
      // printf("%c\n", S[i]);
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}