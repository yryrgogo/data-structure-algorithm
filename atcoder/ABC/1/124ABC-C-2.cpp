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

int main()
{

  string S;
  cin >> S;
  // vector<int> odd(S.size() / 2, 0), even(S.size() / 2);
  int odd = 0, even = 0;
  int half = S.size() / 2;

  rep(i, S.size())
  {
    if ((i + 1) % 2 == 1)
    {
      if (S[i] == '0')
        odd++;
    }
    else
    {
      if (S[i] == '0')
        even++;
    }
  }

  int a, b;
  if (S.size() % 2 == 1)
  {
    a = odd + half - even;
    b = half + 1 - odd + even;
  }
  else
  {
    a = odd + half - even;
    b = half - odd + even;
  }
  cout << min(a, b) << endl;
}