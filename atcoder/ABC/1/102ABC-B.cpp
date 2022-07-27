#include <iostream>
using namespace std;
static const int MAX = 1000000000;

int main()
{

  int N, A[100];
  int nmax = -1;
  int nmin = MAX + 1;
  int now = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];

    if (nmin > A[i]){
      nmin = A[i];
    }
    if (nmax < A[i]){
      nmax = A[i];
    }
  }

  cout << nmax - nmin << endl;

  return 0;
}