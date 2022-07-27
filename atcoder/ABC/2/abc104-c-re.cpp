// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int D, G;
  cin >> D >> G;

  int p[D], c[D];
  rep(i, D)
  {
    cin >> p[i] >> c[i];
  }

  ll ans = INF;

  for (int i = 0; i < 1 << D; i++)
  {
    int sum = 0;
    int cnt = 0;
    int bit[D];

    for (int j = 0; j < D; j++)
    {
      int div = 1 << j;
      bit[j] = (i / div) % 2;
    }

    // コンプリートボーナスの取得
    for (int j = 0; j < D; j++)
    {
      // フラグが立っている = コンプリートボーナスを取得する
      if (bit[j])
      {
        sum += c[j];
        sum += p[j] * 100 * (j + 1);
        cnt += p[j];
      }

      if (sum >= G)
      {
        break;
      }
    }

    // printf("%d : %d : %d", sum, cnt, (1 << D));

    if (sum >= G)
    {
      if (ans > cnt)
      {
        ans = cnt;
      }
      continue;
    }

    // 点数が高い順
    for (int j = D - 1; j >= 0; j--)
    {
      // フラグが立っている = コンプリートボーナスを取得済
      if (bit[j])
      {
        continue;
      }

      int diff = (G - sum);
      if (diff > 0)
      {
        int remain = ceil((double)diff / ((j + 1) * 100));
        if (remain > p[j])
        {
          sum += 100 * j * p[j];
          cnt += p[j];
        }
        else
        {
          sum += 100 * j * remain;
          cnt += remain;
          break;
        }
      }
    }

    if (ans > cnt)
    {
      ans = cnt;
    }
  }

  cout << ans << endl;
}