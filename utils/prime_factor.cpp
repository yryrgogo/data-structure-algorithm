#include <iostream>
#include <vector>
using namespace std;

vector<int> prime_factor(int N)
{
  vector<int> primes;
  int i = 2;

  while (i * i <= N)
  {
    if (N % i == 0)
    {
      primes.push_back(i);
      N /= i;
      continue;
    }

    i++;
  }

  if (N != 1)
  {
    primes.push_back(N);
  }

  return primes;
}

int main()
{
  int N;
  cin >> N;

  // 約数列挙
  vector<int> primes = prime_factor(N);

  for (int i = 0; i < primes.size(); i++)
  {
    cout << primes[i] << endl;
  }
}