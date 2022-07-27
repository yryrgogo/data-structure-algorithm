#include <iostream>
#include <cmath>
using namespace std;

int main()
{

  int N;
  cin >> N;
  int ans = 0;

  for (int n = 1; n <= N; n += 2)
  {

    int cnt = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0)
      {
        cnt++;
      }
    }

    int num = 1;
    for (int i = 2; i <= cnt; i++)
    {
      num *= i;
    }

    if (num + 2 == 8)
    {
      ans++;
    }
  }

  cout << ans;

  return 0;
}
