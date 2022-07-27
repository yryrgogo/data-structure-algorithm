#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &a, const vector<long long> &b) { return a[key] < b[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

int log6(int x)
{
  return (int)(log2(x) / log2(6));
}

int log9(int x)
{
  return (int)(log2(x) / log2(9));
}

int main()
{
  int N;
  cin >> N;

  vi dp(N + 1, 100007);

  dp[N] = 0;
  for (int i = N; i > 0; i--)
  {
    chmin(dp[i - (int)pow(9, log9(i))], dp[i] + 1);
    chmin(dp[i - (int)pow(6, log6(i))], dp[i] + 1);
    chmin(dp[i - 1], dp[i] + 1);
  }
  cout << dp[0] << endl;
}

// int N;
// int ans = 100007;

// void dfs(int x, int depth, int cnt)
// {
//   if (depth == 0)
//   {
//     ans = min(ans, cnt + (N - x));
//     return;
//   }

//   int a = log9(N - x);
//   int b = log6(N - x);

//   if (a > 0)
//   {
//     dfs(x + pow(9, a), depth - 1, cnt + 1);
//   }
//   else
//   {
//     dfs(x, depth - 1, cnt);
//   }
//   if (b > 0)
//   {
//     dfs(x + pow(6, b), depth - 1, cnt + 1);
//   }
//   else
//   {
//     dfs(x, depth - 1, cnt);
//   }
// }

// int main()
// {
//   cin >> N;

//   dfs(0, 20, 0);

//   cout << ans << endl;
// }