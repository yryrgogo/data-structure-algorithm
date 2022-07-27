#include <iostream>
using namespace std;

int main()
{

  int N, X, A[22];
  bool flag = false;

  cin >> N >> X;

  for (int i = 1; i <= N; i++)
  {
    cin >> A[i];
  }

  for (int i = 0; i < (1 << N); i++)
  {
    // 十分な桁数を確保するため30になってる？
    int bit[30], sum = 0;
    for (int j = 0; j < N; j++)
    {
      // 1桁目から順に N 桁目まで1が立っているか確認する
      int Div = (1 << j);
      // 2進数において確認したい桁を1桁目にもってくるため（i / Div）して、2で割り切れるかどうかで1が立つか否か判定している
      bit[j] = (i / Div) % 2;
    }

    // bit の1桁はコインと1:1になっているため、フラグが立っているコインの値のみを足していくことができる
    for (int j = 0; j < N; j++)
    {
      sum += A[j] * bit[j];
    }

    // X と一致する値が存在するかチェック
    if (sum == X)
    {
      flag = true;
    }
  }
}