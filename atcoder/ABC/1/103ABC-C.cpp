#include <iostream>
using namespace std;
using ll = long long;

int main()
{

  int N;

  cin >> N;

  ll A[N];
  ll acc = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    acc += A[i] - 1;
  }

  cout << acc;

  return 0;
}
