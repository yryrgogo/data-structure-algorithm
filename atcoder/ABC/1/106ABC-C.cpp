#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{

  string S;
  ll K;
  cin >> S >> K;
  int cnt = 0;
  int firstNum = 0;

  for (int i = 0; i < S.length(); i++)
  {
    int num = S[i] - '0';
    if (num == 1)
    {
      cnt++;
    }
    else
    {
      firstNum = num;
      break;
    }
  }

  if (cnt >= K)
  {
    cout << 1;
  }
  else
  {
    cout << firstNum;
  }

  return 0;
}