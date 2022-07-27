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

int main()
{

  int N, K;
  cin >> N >> K;

  double ans = 0;
  repd(i, 1, N + 1)
  {
    int cnt = 0;
    int P = i;
    while (P < K)
    {
      P = P * 2;
      cnt++;
    }
    ans += (double(1.0) / double(N)) * (double(1.0) / double(pow(2, cnt)));
  }
  printf("%.12f\n", ans);
}