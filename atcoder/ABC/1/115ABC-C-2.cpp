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

  ll N, K;
  cin >> N >> K;
  ll h[N];
  rep(i, N) cin >> h[i];

  sort(h + 0, h + N);

  ll ans = 1000000007;
  rep(i, N - K + 1)
  {
    ans = min(ans, abs(h[i] - h[i + K - 1]));
  }
  cout << ans;
}