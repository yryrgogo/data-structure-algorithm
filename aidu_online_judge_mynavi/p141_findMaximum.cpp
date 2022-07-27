#include <iostream>
using namespace std;

int findMaximum(int A[], int l, int r)
{
  int u, v, x;
  int m = (l + r) / 2;
  if (l == r - 1)
  {
    return A[l];
  }
  else
  {
    u = findMaximum(A, l, m);
    v = findMaximum(A, m, r);
    x = max(u, v);
  }

  return x;
}

int main()
{
  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int max = findMaximum(A, 0, 5);
  cout << max;
}