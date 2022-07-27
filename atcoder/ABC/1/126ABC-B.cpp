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

  bool before = false;
  bool after = false;
  repd(i, 1, 13)
  {
    if (i == stoi(S.substr(0, 2)))
    {
      before = true;
    }
    if (i == stoi(S.substr(2, 4)))
    {
      after = true;
    }
  }

  if (before && after)
  {
    cout << "AMBIGUOUS" << endl;
  }
  else if (before)
  {
    cout << "MMYY" << endl;
  }
  else if (after)
  {
    cout << "YYMM" << endl;
  }
  else
  {
    cout << "NA" << endl;
  }
}