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
  ll N, A, B, C, D, E;
  vector<ll> M(5, 0);
  cin >> N >> M[0] >> M[1] >> M[2] >> M[3] >> M[4];
  ll minV = *min_element(M.begin(), M.end());
  if ((N % minV) > 0)
    cout << 4 + (N / minV) + 1;
  else
    cout << 4 + (N / minV);
  // cout << 5 + (N / min(M));
  // vector<ll> v(6, 0);
  // ll cnt = 0;
  // ll time = 0;
  // v[0] = N;

  // while (true)
  // {
  //   cnt++;
  //   time++;
  //   if (cnt > 5)
  //     cnt = 5;
  //   repdm(i, cnt - 1, -1)
  //   {
  //     if (v[i] == 0)
  //       continue;
  //     if (v[i] <= M[i])
  //     {
  //       v[i + 1] += v[i];
  //       v[i] = 0;
  //     }
  //     else
  //     {
  //       v[i + 1] += M[i];
  //       v[i] -= M[i];
  //     }
  //   }
  //   if (v[5] >= N)
  //   {
  //     break;
  //   }
  // }
  // cout << time;
}