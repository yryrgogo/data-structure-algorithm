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

  int N, M;
  cin >> N >> M;

  int x[M];
  int diffList[M - 1];

  rep(i, M)
  {
    cin >> x[i];
  }

  sort(x + 0, x + M);

  rep(i, M)
  {
    if (i == 0)
      continue;

    int diff = abs(x[i] - x[i - 1]);
    diffList[i - 1] = diff;
  };

  int ans = 0;
  sort(diffList + 0, diffList + (M - 1));
  rep(i, M - 1 - (N - 1))
  {
    ans += diffList[i];
  };

  cout << ans;
}