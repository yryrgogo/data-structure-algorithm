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

  int N, K;
  cin >> N >> K;
  int A[N];
  rep(i, N)
  {
    cin >> A[i];
  }

  // cout << ceil((N - K) / (K - 1)) + 1 << endl;
  int tmp = (N - K) / (K - 1);
  if ((N - K) % (K - 1) == 0)
  {
    cout << tmp + 1 << endl;
  }
  else
  {
    cout << tmp + 2 << endl;
  }

  // int N, K;
  // cin >> N >> K;

  // int A[N];

  // rep(i, N)
  // {
  //   cin >> A[i];
  // }

  // int a = (N - K) % (K - 1);

  // if (a == 0)
  // {
  //   cout << (N - K) / (K - 1) + 1 << endl;
  // }
  // else
  // {
  //   cout << (N - K) / (K - 1) + 2 << endl;
  // }
}