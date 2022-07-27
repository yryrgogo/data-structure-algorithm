#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
  ll D, G;

  cin >> D >> G;

  int P[D], C[D];
  for (int i = 0; i < D; i++)
  {
    cin >> P[i] >> C[i];
  }

  int ans = pow(10, 9);

  for (int i = 0; i < pow(2, D); i++)
  {
    int score = 0;
    int cnt = 0;
    int max_q_no = 0;
    // 何番目の問をコンプリートするか
    for (int j = 0; j < D; j++)
    {
      // 問題の数だけ2進数を使った判定を行う。2の階乗での全探索になってるので、指数が増えるごとに2進数の桁数も合わせて増える
      // そこに各桁で1が立ってるかどうかを1<<(問題番号-1)を使った論理積で判定する。
      // 2の問題数乗になっているので、問題番号における01と2進数の各桁の01を対応させられる。
      // ここでどの問をコンプリートするかどうかの判定
      // 1<<jを使うとj桁分左にずらした２進数の値が得られるので、1(1), 10(2), 100(4), 1000(8), 10000(16)
      // &で論理積をとることで、問題番号と桁番号を紐付けて01の判定を行える.
      // &を使うとiも2進数変換された上で論理積がとられる
      if (i & (1 << j))
      {
        score += 100 * (j + 1) * P[j] + C[j];
        cnt += P[j];
      }
      // コンプリートしない場合
      else
      {
        max_q_no = j;
      }
    }
    // まだ点数が足りない場合
    if (score < G)
    {
      // 残り
      int remain = G - score;
      // 最大の問題番号をコンプリートしない数だけ解いて達成できるか？
      int q_p = 100 * (max_q_no + 1);
      int need = ceil((remain + (q_p - 1)) / q_p);
      if (need < P[max_q_no])
      {
        cnt += need;
      }
      else
      {
        continue;
      }
    }

    ans = min(ans, cnt);
  }

  cout << ans;

  return 0;
}