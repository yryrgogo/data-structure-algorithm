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
  int N, T;
  cin >> N >> T;
  int c[N], t[N];
  int cost = 1001;
  rep(i, N)
  {
    cin >> c[i] >> t[i];

    if (t[i] <= T)
    {
      if (c[i] < cost)
        cost = c[i];
    }
  }

  if (cost == 1001)
  {
    cout << "TLE";
    return 0;
  }

  cout << cost;
}