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

/* シェルソート */
void shell_sort(int array[], int array_size)
{
  int i, j, h;

  for (h = 1; h <= array_size / 9; h = 3 * h + 1)
  {
    // 間隔hを決める
    for (; h > 0; h /= 3)
    { // hを狭めていく
      /* 以下、挿入ソートとほぼ同じ */
      for (i = h; i < array_size; i++)
      {
        j = i;
        while ((j > h - 1) && (array[j - h] > array[j]))
        {
          swap(&array[j - h], &array[j]);
          j -= h;
        }
      }
    }
  }
}

int main(void)
{
  int array[10] = {2, 1, 8, 5, 4, 7, 9, 0, 6, 3};
  int i;

  printf("Before sort: ");
  for (i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  shell_sort(array, 10);

  printf("After sort: ");
  for (i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}