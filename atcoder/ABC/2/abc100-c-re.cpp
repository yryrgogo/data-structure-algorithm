#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int a[N];
  int count = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
    while (a[i] % 2 == 0)
    {
      count++;
      a[i] /= 2;
    }
  }

  cout << count << endl;
}