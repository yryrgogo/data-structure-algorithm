#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

int main()
{

  int N;
  cin >> N;
  string ans = "";

  if (N == 0)
    cout << '0';

  while (N != 0)
  {
    if (N % (-2) == 0)
    {
      ans = '0' + ans;
    }
    else if (abs(N % (-2)) == 1)
    {
      ans = '1' + ans;
    }

    if (N == 0)
      break;

    N /= -2;
  }

  cout << ans << endl;

  return 0;
}