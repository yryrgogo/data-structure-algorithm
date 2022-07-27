#include <iostream>
#include <math.h>
using namespace std;

// これはNが1-100だから解けるが、1-10000とかになると解けない問題がでる。
// ただ、Nが100の何乗より小さいか調べて、その数-1をNに足してあげれば解けるようになる
int main()
{
  int sum = 0, D, N;

  scanf("%d %d", &D, &N);

  sum = pow(100, D) * N;
  if (log10(sum) / log10(100) == D + 1)
  {
    sum += pow(100, D);
  }

  cout << sum << endl;

  return 0;
};