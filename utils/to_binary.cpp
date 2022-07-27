#include <iostream>
using namespace std;
typedef long long ll;

void Binary(int x)
{
  int bit[30];
  for (int i = 0; i < 10; i++)
  {
    // Div は 1, 2, 4, 8, 16,,, となる
    int Div = (1 << i);

    // Div は10進数でいうところの10, 10^2, 10^3,,, で割ることに相当する。つまり、桁数を1つずつ小さくして残った数の1桁目が2で割り切れるかどうかをチェックしている
    bit[i] = (x / Div) % 2;
    printf("%d : %d : %d : %d\n", x, Div, x / Div, bit[i]);
  }
}

int main()
{
  Binary(4);
  Binary(7);
  Binary(15);
  Binary(16);
}