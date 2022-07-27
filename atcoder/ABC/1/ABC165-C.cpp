// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;

int N, M, Q;
int a[55], b[55], c[55], d[55];
int ans = 0;

int check(int A[11])
{
  int p = 0;
  rep(i, Q)
  {
    if (c[i] == A[b[i] - 1] - A[a[i] - 1])
    {
      p += d[i];
    }
  }

  return p;
}

void dfs(int depth, int A[11], int start)
{
  if (depth == N)
  {
    ans = max(ans, check(A));
    return;
  }

  repd(num, start, M + 1)
  {
    A[depth] = num;
    dfs(depth + 1, A, num);
  }
}

int main()
{
  cin >> N >> M >> Q;
  rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

  int A[11] = {0};
  dfs(0, A, 1);

  cout << ans << endl;
}