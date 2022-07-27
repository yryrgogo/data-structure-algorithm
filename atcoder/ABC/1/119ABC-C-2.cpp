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
int seq[4] = {0, 1, 2, 3};
int ANS = 100000;
int l[8];

int calcMP(vector<int> m)
{
  if (m[1] == 0 || m[2] == 0 || m[3] == 0)
    return 10000;
  return abs(A - m[1]) + abs(B - m[2]) + abs(C - m[3]);
}

int dfs(int depth, vector<int> m, int mp)
{
  if (depth == 0)
  {
    mp += calcMP(m);
    return mp;
  }

  for (auto s : seq)
  {
    int tmp = mp;
    vector<int> mm = m;
    if (s != 0)
    {
      if (mm[s] == 0)
      {
        mm[s] = l[depth - 1];
      }
      else
      {
        tmp += 10;
        mm[s] += l[depth - 1];
      }
    }
    tmp = dfs(depth - 1, mm, tmp);
    ANS = min(ANS, tmp);
  }

  return ANS;
}

int main()
{
  cin >> N >> A >> B >> C;
  rep(i, N) cin >> l[i];
  int mp = 0;

  vector<int> m(4, 0);

  dfs(N, m, mp);

  cout << ANS;
}