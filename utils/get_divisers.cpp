#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisers(int N)
{
  vector<int> divisers = {1, N};
  int i = 2;

  for (int i = 2; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      divisers.push_back(i);
      if (i != N)
      {
        divisers.push_back(N / i);
      }
    }
  }

  sort(divisers.begin(), divisers.end());

  return divisers;
}

int main()
{
  int N;
  cin >> N;

  vector<int> divisers = get_divisers(N);

  for (int i = 0; i < divisers.size(); i++)
  {
    cout << divisers[i] << endl;
  }
}