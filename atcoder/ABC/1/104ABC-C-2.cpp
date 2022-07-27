#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

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
  repd(i, 1, pow(2, D) + 1)
  {
    int score = 0;
    int cnt = 0;

    rep(j, D)
    {
      if (i & 1 << j)
      {
        // j番目の問をComplete
        cnt += p[j + 1];
        score += 100 * (j + 1) * p[j + 1] + c[j + 1];
      }
    }
    // 足りない点数分の問を解く
    if (G > score)
    {
      repdm(k, D, 0)
      {
        if ((i & 1 << (k - 1)) == 0)
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
        if (score >= G)
          break;
      }
    }

    if (ans > cnt)
    {
      ans = cnt;
    }
  }
  cout << ans << endl;
}