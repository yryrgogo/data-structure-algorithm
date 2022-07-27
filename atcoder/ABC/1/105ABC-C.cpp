#include <iostream>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

int main()
{

  int N;
  cin >> N;
  string ans = "";

  if (N == 0)
    cout << '0';

  while (N != 0)
  {
    if (N % (-2) == 0)
    {
      ans = '0' + ans;
    }
    else if (abs(N % (-2)) == 1)
    {
      ans = '1' + ans;
      N -= 1;
    }

    if (N == 0)
      break;
    N /= -2;
  }

  cout << ans;

  return 0;
}