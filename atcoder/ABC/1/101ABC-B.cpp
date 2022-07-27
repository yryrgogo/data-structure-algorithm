#include <iostream>
#include <string>
using namespace std;

int ctoi(char c)
{
  switch (c)
  {
  case '0':
    return 0;
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  default:
    return 0;
  }
}

int S(string N)
{
  int sum = 0;

  for (int i = 0; i < N.length(); i++)
  {
    char num = N[i];
    // cout << typeid(num).name() << endl;
    sum += ctoi(num);
  }

  return sum;
}

int S2(int N){

  int sum = 0;

  while (N != 0) {
    sum += N % 10;
    N /= 10;
  }

  return sum;
}

int main()
{

  int N;

  cin >> N;

  int result = S2(N);

  if (N % result == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}