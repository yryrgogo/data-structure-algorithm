#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i] >> h[i];
  }

  int MAX = 100;

  for (int posY = 0; posY <= MAX; posY++)
  {
    for (int posX = 0; posX <= MAX; posX++)
    {
      // 頂上がどれくらいの高さであって欲しいか
      // -1はまだよくわからない時。0以上は確定してる時
      // -2はダメだってわかった時
      int needH = -1;

      for (int i = 0; i < N; i++)
      {
        if (h[i] > 0)
        {
          // この頂点から見て、頂上がposY, posXの時に、
          // どれくらいの高さがあって欲しいかを求める
          int tmp = h[i] + abs(posY - y[i]) + abs(posX - x[i]);
          cout << tmp << endl;

          // 最初のループ
          if (needH == -1)
          {
            needH = tmp;
          }
          else
          {
            if (needH != tmp)
            {
              needH = -2;
              break;
            }
          }
        }
      }
      // ダメだったら他の場所を探す
      if (needH == -2)
        continue;

      for (int i = 0; i < N; i++)
      {
        if (h[i] == 0)
        {
          int dist = abs(posY - y[i]) + abs(posX - x[i]);

          if (needH > dist)
          {
            needH = -2;
            break;
          }
        }
      }

      if (needH == -2)
        continue;

      cout << posX << " " << posY << " " << needH << endl;
      return 0;
    }
  }
}