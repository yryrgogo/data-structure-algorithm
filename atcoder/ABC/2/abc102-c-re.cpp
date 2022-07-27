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

  vector<ll> A(N);
  ll sum = 0;

  rep(i, N)
  {
    cin >> A[i];
    A[i] -= i + 1;
  }

  sort(A.begin(), A.end());

  ll b = A[A.size() / 2];

  rep(i, N)
  {
    sum += abs(b - A[i]);
  }

  cout << sum << endl;

  // rep(i, N)
  // {
  //   cin >> A[i];
  //   sum += A[i];
  // }

  // int tmp = sum / N;
  // int b = tmp - (N / 2);

  // int ans = 0;

  // rep(i, N)
  // {
  //   ans += abs(A[i] - (b + i));
  // }

  // cout << ans << endl;
}