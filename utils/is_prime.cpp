#include <iostream>
using namespace std;

bool is_prime(int N)
{

  for (int i = 2; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int N;
  cin >> N;

  if (is_prime(N))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}