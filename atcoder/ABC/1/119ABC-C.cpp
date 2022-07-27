#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int calc(vector<int> v, vector<int> l, int N, int A, int B, int C)
{
  int mp = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  rep(i, N)
  {
    int d = v[i + 1];
    if (d == 0)
    {
      if (a > 0)
        mp += 10;
      int ai = l[i];
      a += ai;
    }
    else if (d == 1)
    {
      if (b > 0)
        mp += 10;
      int bi = l[i];
      b += bi;
    }
    else if (d == 2)
    {
      if (c > 0)
        mp += 10;
      int ci = l[i];
      c += ci;
    }
  }

  if (a == 0 || b == 0 || c == 0)
    return 1000000007;

  mp += abs(A - a);
  mp += abs(B - b);
  mp += abs(C - c);

  return mp;
}

int dfs(int depth, vector<int> v, vector<int> l, int N, int A, int B, int C)
{

  int ans = 1000000000;
  // base case
  if (depth == 0)
  {
    return calc(v, l, N, A, B, C);
  }

  rep(i, 4)
  {
    v[depth] = i;
    int result = dfs(depth - 1, v, l, N, A, B, C);
    ans = min(result, ans);
  }

  return ans;
}

int main()
{

  int N, A, B, C;
  cin >> N >> A >> B >> C;

  vector<int> l(N);
  vector<int> v(N + 1);
  rep(i, N) cin >> l[i];

  cout << dfs(N, v, l, N, A, B, C);
}