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

  int L[N];
  int sum = 0;
  int max_v = -1;
  rep(i, N)
  {
    cin >> L[i];
    sum += L[i];

    if (L[i] > max_v)
    {
      max_v = L[i];
    }
  }

  if (sum - max_v > max_v)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}