#include <iostream>
using namespace std;
#define MAX 10000
typedef long long llong;

int n, k;
llong T[MAX];

// 最大積載量Pのk台のトラックで何個の荷物を積めるか？
int check(llong P)
{
  int i = 0;
  for (int j = 0; j < k; j++)
  {
    llong s = 0;
    while (s + T[i] <= P)
    {
      s += T[i];
      i++;
      if (i == n)
        return n;
    }
  }
  return i;
}

int solve()
{
  llong left = 0;
  llong right = 100000 * 10000; // 荷物の個数＊1個当たりの最大重量
  llong mid;
  while (right - left > 0)
  {
    mid = (left + right) / 2;
    int v = check(mid);
    if (v >= n)
    {
      right = mid;
    }
    else
    {
      left = mid + 1;
    }
  }
  return right;
}

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> T[i];
  llong ans = solve();
  cout << ans << endl;
}