#include <iostream>
using namespace std;

// int allowNum(int P, int k, int w[])
// {
//   max(w);
// }

void print(int N, int S[])
{
  for (int i = 0; i < N; i++)
  {
    cout << S[i];
  }
  cout << endl;
}

void insertionSort(int N, int S[])
{
  for (int i = 1; i < N; i++)
  {
    int v = S[i];
    int j = i - 1;
    while (v < S[j] & j >= 0)
    {
      S[j + 1] = S[j];
      j--;
    }
    S[j + 1] = v;
  }
}

int selectTrack(int k, int t[], int n, int w[], int P)
{
  for (int i = 0; i < k; i++)
  {
    t[i] = 0;
  }

  insertionSort(n, w);
  for (int i = n - 1; i >= 0; i--)
  {
    insertionSort(k, t);
    int tmp = w[i];
    t[0] += tmp;
    print(k, t);

    if (t[0] > P)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  int w[n], t[k], P, sum = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &w[i]);
  }
  int p = 0;
  int flag = 1;
  while (flag == 1)
  {
    p++;
    flag = selectTrack(k, t, n, w, p);
  }

  cout << p << endl;

  return 0;
}