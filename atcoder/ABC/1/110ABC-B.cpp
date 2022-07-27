#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int main()
{
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i, N) cin >> x[i];
  rep(i, M) cin >> y[i];

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int maxX = x[N - 1];
  int minY = y[0];

  if (maxX < minY)
  {
    if (X < Y && X < minY && maxX < Y)
    {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}