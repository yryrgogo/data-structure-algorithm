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

int main()
{

  int N;
  cin >> N;
  int h[N];
  int height = 0;
  int ans = 0;
  rep(i, N)
  {
    cin >> h[i];

    if (height < h[i])
    {
      ans += h[i] - height;
    }
    height = h[i];
  }

  cout << ans;
}