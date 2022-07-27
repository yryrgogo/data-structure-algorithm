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

  string S;
  cin >> S;

  int oddW = 0;
  int oddB = 0;
  int evenW = 0;
  int evenB = 0;

  rep(i, S.size())
  {
    if (i % 2 == 0)
    {
      if (S[i] == '1')
        evenW++;
      else if (S[i] == '0')
        evenB++;
    }
    else if (i % 2 == 1)
    {
      if (S[i] == '1')
        oddW++;
      else if (S[i] == '0')
        oddB++;
    }
  }

  int p1 = oddW + evenB;
  int p2 = oddB + evenW;
  if (p1 > p2)
    cout << p2 << endl;
  else
    cout << p1 << endl;
}