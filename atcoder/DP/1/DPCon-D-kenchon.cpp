// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int N;
ll W, weight[110], value[110];

// dpテーブル。配列の２次元目は、その時のナップサックのweightそのものを表し、そこにvalueを入れるようになっている
ll dp[110][100010] = {0};

int main()
{
  cin >> N >> W;
  rep(i, N) cin >> weight[i + 1] >> value[i + 1];

  rep(i, N)
  {
    rep(sum_w, W + 1)
    {
      // i番目の品物を選ぶ場合
      if (sum_w - weight[i + 1] >= 0)
      {
        // sum_w - weight[i+1]は新しいナップサックの状態（weight）を
        chmax(dp[i + 1][sum_w], dp[i][sum_w - weight[i + 1]] + value[i + 1]);
      }

      chmax(dp[i + 1][sum_w], dp[i][sum_w]);
    }
  }

  cout << dp[N][W];
}