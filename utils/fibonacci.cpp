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

vector<long long> memo;

long long fibo(int N)
{
  if (N == 0)
    return 0;
  else if (N == 1)
    return 1;

  if (memo[N] != -1)
    return memo[N];

  return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main()
{
  memo.assign(50, -1);

  fibo(49);

  for (int N = 0; N < 50; ++N)
  {
    cout << N << " : " << memo[N] << endl;
  }
}