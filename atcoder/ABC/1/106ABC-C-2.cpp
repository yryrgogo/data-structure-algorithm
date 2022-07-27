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
  string S;
  ll K;
  cin >> S >> K;

  ll cnt = 0;
  string last;
  for (int i = 0; i < S.size(); i++)
  {
    if ((S[i] - '0') == 1)
    {
      cnt++;
      continue;
    }
    last = S[i];
    break;
  }

  if (cnt >= K)
  {
    cout << 1;
    return 0;
  }
  cout << last;
}