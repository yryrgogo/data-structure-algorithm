#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000009;

int n, A;
int a[110];

int dp[110][10010];

int main()
{
  cin >> n >> A;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= A; j++)
    {
      // これは単にjという値を満たす時にa[i]を使わないパターン数を追加しているだけ
      // i+1番目の品を検討するフェーズだが、jにできる組み合わせ数を数え上げるためi+1を選ばないパターンの値も足しておく必要がある
      dp[i + 1][j] += dp[i][j];
      if (j - a[i] >= 0)
        // これが成り立つのはa[i]を足す余裕のある(j - a[i])という状態をベースにしてそこにa[i]を追加することを前提にしているから。そのベースの状態にa[i]を追加することでもjにできるため、dp[i][j-a[i]]にできる組み合わせ数を追加できる
        dp[i + 1][j] += dp[i][j - a[i]];
    }
  }

  cout << dp[n][A] << endl;
}