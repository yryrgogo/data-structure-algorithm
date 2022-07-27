#include <bits/stdc++.h>
using namespace std;

/* 値を入れ替える関数 */
void swap(int *x, int *y)
{
  int temp; // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

int moveCnt = 0;
int compare = 0;

/* 挿入ソート */
void insertion_sort(int x[], int array_size)
{
  int i, j, tmp;

  for (j = 1; j < array_size; j++)
  {
    // 先頭から順にソート
    tmp = x[j];
    moveCnt++;
    for (i = j - 1; i >= 0; i--)
    {
      compare++;
      if (x[i] > tmp)
      {
        x[i + 1] = x[i];
        moveCnt++;
        if (moveCnt == 4)
        {
          cout << "x[i]: " << x[i] << endl;
        }
      }
      else
      {
        break;
      }
      x[i + 1] = tmp;
      moveCnt++;
      if (moveCnt == 4)
      {
        cout << "tmp: " << tmp << endl;
      }
    }
  }
}

int main(void)
{
  int N = 5;
  int x[5] = {30, 50, 20, 10, 40};
  int i;

  printf("Before sort: ");
  for (i = 0; i < N; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n");

  insertion_sort(x, N);

  printf("After sort: ");
  for (i = 0; i < N; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n");

  return 0;
}