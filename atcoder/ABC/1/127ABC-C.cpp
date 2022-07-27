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
  int N, M;
  cin >> N >> M;

  int L[M], R[M];
  int maxL = 0;
  int minR = 10000000;
  rep(i, M)
  {
    cin >> L[i] >> R[i];
    if (maxL < L[i])
      maxL = L[i];
    if (minR > R[i])
      minR = R[i];
  }
  cout << max((minR - maxL) + 1, 0) << endl;
}
