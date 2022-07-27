#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
static const int MAX = 200000;

int main()
{
  // 配列のサイズを宣言
  int R[MAX], n;

  // 入力値の数を取得
  cin >> n;
  // 入力値の数ぶんループして配列に格納する
  for (int i = 0; i < n; i++)
    cin >> R[i];

  // 最大値がありえる数字より小さくなるように設定
  int maxv = -2 * pow(10, 9);
  // 最大と最小が最も大きくなる時の数字を求めるので、新しい数字が登場するごとに最小値かどうか判定する
  int minv = R[0];

  // 2つ目の数字からスタート
  for (int i = 1; i < n; i++)
  {
    // 考えうる最小の最大値と現状の最大値はどちらが大きいか？（初回）
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
  }

  // maxvを出力
  cout << maxv << endl;

  return 0;
}
