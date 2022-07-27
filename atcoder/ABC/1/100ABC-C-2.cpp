#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int fact(int num, int cnt)
{
  if (num % 2 != 0)
    return cnt;

  cnt++;
  return fact(num / 2, cnt);
}

int main()
{

  int N;
  cin >> N;
  int a[N];

  int cnt = 0;
  rep(i, N)
  {
    cin >> a[i];
    cnt = fact(a[i], cnt);
  }

  cout << cnt;

  return 0;
}