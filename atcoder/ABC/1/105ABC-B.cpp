#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
  int N;
  cin >> N;

  while (N >= 4)
  {
    if (N % 4 == 0 || N % 7 == 0)
    {
      cout << "Yes";
      return 0;
    }
    N -= 4;
  }
  cout << "No";

  return 0;
}