#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int main()
{
  int N;
  cin >> N;
  int a[N];
  int ans = 0;
  rep(i, N)
  {
    cin >> a[i];
    ans += a[i] - 1;
  };

  cout << ans;
}