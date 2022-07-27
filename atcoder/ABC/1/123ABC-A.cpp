#include <iostream>
using namespace std;

int main()
{
  int A[5], k;
  // int a, b, c, d, e, k;

  for (int i = 0; i < 5; i++)
  {
    cin >> A[i];
  }
  cin >> k;

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (i == j)
        continue;
      if (A[i] > A[j])
        continue;
      if ((A[j] - A[i]) > k)
      {
        cout << ":(";
        return 0;
      }
    }
  }

  cout << "Yay!";
}
