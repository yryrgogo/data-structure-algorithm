/*
ネタバラシをすると、入力の大半はどーでも良い。
戦略
操作をする区間がある。
その区間がどうなっているか？
連結成分が全体を含まないとだめ
//
連結グループという単位で考える
グループ数がgだったとすると、
Nは、
N <= K + (K-1)(g-1)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 100000

void minimization()
{
  int n, k;
  cin >> n >> k;

  cout << ceil((float)(n - 1) / (float)(k - 1)) << "\n";
}

int main()
{

  int N, K;
  scanf("%d %d", &N, &K);

  int A[N], minNum = MAX + 1;
  vector<int> minIndexs;

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }
  int g;
  int a = (N - K) % (K - 1);
  if (a == 0)
  {
    g = (N - K) / (K - 1) + 1;
  }
  else
  {
    g = (N - K) / (K - 1) + 2;
  }

  // cout << g << endl;

  // for (int i = 0; i < N; i++)
  // {
  //   scanf("%d", &A[i]);
  //   if (A[i] < minNum)
  //   {
  //     minNum = A[i];
  //     minIndexs.clear();
  //   }
  //   if (A[i] == minNum)
  //   {
  //     minIndexs.push_back(i);
  //   }
  // }

  // int cnt = 0;
  // // headは常に最小値
  // int minHead = 0;
  // int head = minIndexs[minHead];

  // if (head > 0)
  // // 左端から埋める
  // {
  //   if ((head + 1) >= K)
  //   {
  //     cnt += ceil(head / (K - 1));
  //     if ((head) % (K - 1) != 0)
  //     {
  //       head += (K - 1) - (head) % (K - 1);
  //     }
  //   }
  //   else
  //   {
  //     cnt++;
  //     head = K - 1;
  //   }
  //   // 処理済の最小値インデックスを更新
  // }
  // else
  // {
  //   head += K - 1;
  //   cnt++;
  // }
  // minHead++;

  // while (head + 1 < N)
  // {
  //   if (minHead + 1 <= minIndexs.size())
  //   {
  //     // 次のK個に最小値を含まない場合
  //     if ((head + K) < minIndexs[minHead])
  //     {
  //       // headの最小値を含むK個を置き換えるので、+=K-1
  //       head += K - 1;
  //       cnt++;
  //     }
  //     else
  //     {
  //       // headの最小値を含まないK個を置き換えるので、+=K
  //       head += K;
  //       cnt++;
  //       minHead++;
  //     }
  //   }
  //   else
  //   {
  //     // headの最小値を含むK個を置き換えるので、+=K-1
  //     head += K - 1;
  //     cnt++;
  //   }
  // }

  // cout << cnt;

  return 0;
}