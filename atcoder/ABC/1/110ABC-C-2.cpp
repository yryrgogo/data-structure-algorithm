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

  string S, T;
  cin >> S >> T;
  vector<int> good(10000, -1);
  vector<int> good2(10000, -1);

  rep(i, S.size())
  {
    if (good[S[i] - '0'] == -1)
    {
      good[S[i] - '0'] = T[i] - '0';
    }
    else
    {
      if (good[S[i] - '0'] != T[i] - '0')
      {
        cout << "No";
        return 0;
      };
    }

    if (good2[T[i] - '0'] == -1)
    {
      good2[T[i] - '0'] = S[i] - '0';
    }
    else
    {
      if (good2[T[i] - '0'] != S[i] - '0')
      {
        cout << "No";
        return 0;
      };
    }
  }
  cout << "Yes";
}