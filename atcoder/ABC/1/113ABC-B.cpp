#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int main()
{
  int N, T, A;
  cin >> N;
  cin >> T >> A;
  int h[N];
  int diff = 10000 * 10000;
  int num = 0;
  rep(i, N)
  {
    cin >> h[i];
    int temp = T * 1000 - h[i] * 6;
    if (abs(A * 1000 - temp) < diff)
    {
      diff = abs(A * 1000 - temp);
      num = i + 1;
    }
  }

  cout << num;
}