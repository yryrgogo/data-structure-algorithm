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

int N, A, B, C;
vector<int> l(8);

int dfs(int now, int a, int b, int c)
{

  if (now == N)
  {
    if (a == 0 || b == 0 || c == 0)
      return 999999;
    else:
      return abs(A - a) + abs(B - b)+ abs(C - c);
  }

  int ans1 = dfs()
}

int main()
{
  cin >> N >> A >> B >> C;
  rep(i, N) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
}