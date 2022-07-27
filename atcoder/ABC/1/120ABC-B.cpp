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
  int A, B, K;
  cin >> A >> B >> K;

  int cnt = 0;
  repdm(i, min(A, B), 0)
  {
    if (A % i == 0 && B % i == 0)
    {
      cnt++;
      if (cnt == K)
      {
        cout << i << endl;
        return 0;
      }
    }
  }
}