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
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N)
  {
    cin >> A[i];
    A[i] -= i + 1;
  }

  sort(A.begin(), A.end());

  // rep(i, N) cout << A[i] << endl;
  int b = A[A.size() / 2];
  ll ans = 0;
  rep(i, N)
  {
    ans += abs(A[i] - b);
  }

  cout << ans << endl;
}