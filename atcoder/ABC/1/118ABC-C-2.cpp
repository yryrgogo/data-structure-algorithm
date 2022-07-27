#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
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
  int a[N];

  int pre = 0;
  rep(i, N)
  {
    cin >> a[i];
    if (i == 0)
    {
      pre = a[i];
      continue;
    }
    pre = gcd(pre, a[i]);
  }
  cout << pre;
}