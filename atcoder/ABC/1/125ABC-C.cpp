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
  rep(i, N)
  {
    cin >> A[i];
  }

  int L[N + 2];
  int R[N + 2];

  repd(i, 0, N)
  {
    if (i == 0)
    {
      L[i] = A[i];
      continue;
    }
    L[i] = gcd(L[i - 1], A[i]);
  }

  repdm(i, N - 1, 0)
  {
    if (i == N - 1)
    {
      R[i] = A[i];
      continue;
    }
    R[i] = gcd(R[i + 1], A[i]);
  }

  int ans = 0;
  int d = 0;
  rep(i, N)
  {
    if (i == 0)
    {
      d = R[i + 1];
    }
    else if (i == N - 1)
    {
      d = L[i - 1];
    }
    else
    {
      d = gcd(L[i - 1], R[i + 1]);
    }
    if (ans < d)
      ans = d;
  }
  cout << ans;
}