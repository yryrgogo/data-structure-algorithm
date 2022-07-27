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

  int N, K;
  cin >> N >> K;

  double ans = 0;

  repd(i, 1, N + 1)
  {
    int p = i;
    int cnt = 0;
    while (true)
    {
      if (p >= K)
        break;
      p *= 2;
      cnt++;
    }
    double a = (double)1 / (double)N;
    double b = pow((double)1 / 2, cnt);
    ans += a * b;
  }

  printf("%.12f", ans);
}