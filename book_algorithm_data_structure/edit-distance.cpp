#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

const int INF = 1 << 29;

int main()
{
  string S, T;
  cin >> S >> T;

  vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

  dp[0][0] = 0;

  for (int i = 0; i <= S.size(); i++)
  {
    for (int j = 0; j <= T.size(); j++)
    {
      // S, T の両方に i, j番目それぞれの文字を挿入するケース
      if (i > 0 && j > 0)
      {
        if (S[i - 1] == T[j - 1])
        {
          chmin(dp[i][j], dp[i - 1][j - 1]);
        }
        else
        {
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }

      if (i > 0)
      {
        // i の index が先行しているケース（i 番目の文字のみ追加して、その文字を削除して文字列を一致させる）
        // より正確には、S の文字列にいくつかの空白を追加しているケース、か
        chmin(dp[i][j], dp[i - 1][j] + 1);
      }

      if (j > 0)
      {
        // j の index が先行しているケース（j 番目の文字のみ追加して、その文字を削除して文字列を一致させる）
        // より正確には、T の文字列にいくつかの空白を追加しているケース、か
        chmin(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }

  cout << dp[S.size()][T.size()] << endl;
}