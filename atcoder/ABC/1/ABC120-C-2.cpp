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

  string S;
  cin >> S;
  int cnt0 = 0;
  int cnt1 = 0;
  rep(i, S.size())
  {
    if (S[i] == '0')
      cnt0++;
    if (S[i] == '1')
      cnt1++;
  }
  cout << S.size() - abs(cnt1 - cnt0);
}