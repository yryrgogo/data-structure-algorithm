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

int height(int H, int X, int Y, int Cx, int Cy)
{
  return H + abs(X - Cx) + abs(Y - Cy);
}

int main()
{

  int N;
  cin >> N;

  int x[N], y[N], h[N];

  rep(i, N) cin >> x[i] >> y[i] >> h[i];

  int MAX = 101;
  int l[MAX][MAX][N];

  repd(i, 0, MAX)
  {
    repd(j, 0, MAX)
    {
      int cnt = 1;
      int ansH = 0;
      int outH = 0;

      rep(k, N)
      {
        int x0 = x[k];
        int y0 = y[k];
        int h0 = h[k];
        if (h0 == 0)
        {
          cnt++;
          continue;
        }

        l[i][j][k] = height(h0, x0, y0, i, j);

        if (ansH == 0)
        {
          ansH = l[i][j][k];
          continue;
        }
        if (ansH != l[i][j][k])
          break;
        if (ansH < outH)
          break;
        cnt++;
      }

      if (cnt < N)
        continue;

      rep(k, N)
      {
        int x0 = x[k];
        int y0 = y[k];
        int h0 = h[k];
        if (h0 == 0)
        {
          outH = height(h0, x0, y0, i, j);
          if (ansH > outH)
          {
            cnt = 0;
          }
        }
      }

      if (cnt < N)
        continue;

      cout << i << " " << j << " " << ansH << endl;
      return 0;
    }
  }
}