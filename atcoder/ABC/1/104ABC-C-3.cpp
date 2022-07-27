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

tuple<int, int> dfs(int depth, int score, int cnt, int p[], int c[], int ans, int G)
{
  // Base Case
  if (depth == 0)
  {
    return forward_as_tuple(score, cnt, ans);
  }

  rep(i, 2)
  {
    if (i)
    {
      cnt += p[depth];
      score += p[depth] * 100 * depth + c[depth];
    }
    tie(score, cnt, ans) = dfs(depth - 1, score, cnt, p, c, ans, G);

    // 足りない点数分の問を解く
    if (G > score)
    {
      repdm(k, D, 0)
      {
        if ((depth == k && i != 1) || depth != k)
        {
          int remain = ceil((float)(G - score) / (float)(100 * k));
          if (remain <= p[k])
          {
            cnt += remain;
            score += remain * 100 * k;
          }
          else
          {
            cnt += p[k];
            score += p[k] * 100 * k;
          }
        }
        break;
      }
    }

    if (ans > cnt)
      ans = cnt;
  }

  return forward_as_tuple(store, cnt, ans);
  // if (pat & 1 << (depth - 1))
  // {
  //   cnt += p[depth];
  //   score += p[depth] * 100 * depth + c[depth];
  // }
}

int main()
{
  int D, G;
  cin >> D >> G;

  int p[D + 1], c[D + 1];

  repd(h, 1, D + 1)
  {
    cin >> p[h] >> c[h];
  }

  int ans = 1001;
  int score = 0;
  int cnt = 0;
  tie(score, cnt, ans) = dfs(D, score, cnt, p, c, ans, G);
  cout << ans;
}