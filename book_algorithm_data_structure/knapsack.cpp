#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

template <class T>
void chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
  }
}

int main()
{
  int N;
  ll W;
  cin >> N >> W;

  vector<ll> value(N), weight(N);

  for (int i = 0; i < N; i++)
  {
    cin >> weight[i] >> value[i];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

  for (int i = 0; i < N; i++)
  {
    for (int w = 0; w <= W; w++)
    {
      // i の商品を入れる場合（w に weight[i] をいれるスペースがあれば）
      if (w - weight[i] >= 0)
      {
        // i の商品を入れる前の状態（iの商品を検討し終えた状態）にiの商品を入れて最大値を更新するか確認
        chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
      }

      // i の商品を入れない場合
      chmax(dp[i + 1][w], dp[i][w]);
    }
  }
}
