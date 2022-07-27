#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  if (n >= m)
  {
    cout << 0;
    return 0;
  }

  vector<int> x(m);
  for (int i = 0; i < m; i++)
  {
    cin >> x[i];
  }

  sort(x.begin(), x.end());
  vector<int> d(m - 1);

  for (int i = 0; i < m - 1; i++)
  {
    d[i] = x[i + 1] - x[i];
  }

  sort(d.begin(), d.end());

  int ans = 0;
  for (int i = 0; i < d.size() - (n - 1); i++)
  {
    ans += d[i];
  }

  cout << ans;
}