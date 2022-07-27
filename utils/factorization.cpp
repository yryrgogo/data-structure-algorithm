#include <iostream>
#include <vector>
using namespace std;

bool getPrimeNumber(int n)
{
  if (n < 2)
  {
    return false;
  }
  else if (n == 2)
  {
    return true;
  }

  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }

  return true;
}

// 素因数分解（約数列挙ではない）
int factorization(int n)
{

  vector<vector<int>> v;

  // 理想は素数の配列で判定したいが、n^(1/2)のループ数となるので妥協(良い素数リストがあればそっちが良い)
  for (int i = 2; i * i < n; i++)
  {
    if (n % i == 0 && getPrimeNumber(i))
    {
      cout << i << endl;
    }
  }

  return 0;
}

int main()
{
  factorization(100);
}