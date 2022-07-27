#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int A[N];

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  vector<int> v;

  for (int i = 0; i < N; i++)
  {
    if (A[i] % 2 == 0)
    {
      v.push_back(A[i]);
    }
  }
  int cntDiv = 0;
  for (int i = 0; i < v.size(); i++)
  {
    while (true)
    {
      if (v[i] % 2 == 0)
      {
        cntDiv++;
      }
      else
      {
        break;
      }
      v[i] /= 2;
    }
  }
  cout << cntDiv;
}