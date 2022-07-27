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

int N, Y;
int yen[3] = {10000, 5000, 1000};

void dfs(int depth, int sum, int cnt[3])
{
  if (depth == 0)
  {
    if (sum == Y)
    {
      cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
      exit(0);
    }
    return;
  }

  rep(i, 3)
  {
    int tmp = sum;
    tmp += yen[i];
    cnt[i]++;
    dfs(depth - 1, tmp, cnt);
    cnt[i]--;
  }
}

int main()
{
  cin >> N >> Y;

  int cnt[3] = {0};

  // dfs(N, 0, cnt);

  rep(i, N + 1)
  {
    rep(j, N + 1)
    {
      if (i + j > N)
        continue;
      if (yen[2] * (N - i - j) == Y - yen[0] * i - yen[1] * j)
      {
        cout << i << " " << j << " " << N - i - j << endl;
        exit(0);
      }
    }
  }

  cout << "-1 -1 -1" << endl;
}