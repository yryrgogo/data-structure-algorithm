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

int gcd(int x, int y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int main()
{
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];
  int lgcd[N];
  int rgcd[N];
  rep(i, N)
  {
    if (i == 0)
    {
      lgcd[i] = A[i];
      rgcd[N - 1 - i] = A[N - 1 - i];
      continue;
    }
    lgcd[i] = gcd(A[i], lgcd[i - 1]);
    rgcd[N - 1 - i] = gcd(A[N - 1 - i], rgcd[N - 1 - i + 1]);
  }

  int ans = 0;
  rep(i, N)
  {
    if (i == 0)
    {
      ans = max(ans, rgcd[i + 1]);
      continue;
    }
    if (i == N - 1)
    {
      ans = max(ans, lgcd[i - 1]);
      continue;
    }
    ans = max(gcd(lgcd[i - 1], rgcd[i + 1]), ans);
  }
  cout << ans << endl;
}