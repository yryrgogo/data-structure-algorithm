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

ll N;
int ANS = 0;
int sft[] = {7, 5, 3};

void dfs(ll sum, map<int, int> m1)
{
  if (sum <= N)
  {
    if (m1[3] && m1[5] && m1[7])
      ANS++;

    for (auto n : sft)
    {
      map<int, int> m2;
      m2[n] = 1;
      dfs(sum * 10 + n, m2);
    }
  }
}

int main()
{
  cin >> N;
  map<int, int> m;
  dfs(0, m);
  cout << ANS << endl;
}