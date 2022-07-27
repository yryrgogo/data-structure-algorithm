#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int N, M;
int P[1000000], Y[1000000];
vector<int> yd[100001];

int main()
{
  cin >> N >> M;
  rep(i, M) cin >> P[i] >> Y[i], yd[P[i]].push_back(Y[i]);
  rep(i, N) sort(yd[i + 1].begin(), yd[i + 1].end());
  rep(i, M) printf("%012lld\n", ll(P[i]) * 1000000 + int(lower_bound(yd[P[i]].begin(), yd[P[i]].end(), Y[i]) - yd[P[i]].begin()) + 1);

  return 0;
}