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
  int N, K;
  cin >> N >> K;
  int a[N];
  rep(i, N) cin >> a[i];
  cout << ceil((float)(N - 1) / (float)(K - 1));
}