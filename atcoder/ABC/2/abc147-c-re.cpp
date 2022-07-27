#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &alpha, const vector<long long> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int N;
  cin >> N;
  int A[N];
  vvi g(N, vi(N, -1));

  rep(i, N)
  {
    cin >> A[i];
    rep(j, A[i])
    {
      int x, y;
      cin >> x >> y;
      g[i][x - 1] = y;
    }
  }

  int ans = 0;
  rep(i, 1 << N)
  {
    bool ok = true;
    vi d(N);
    rep(j, N)
    {
      if (1 & i >> j)
      {
        d[j] = 1;
      }
    }

    rep(j, N)
    {
      if (d[j])
      {
        rep(k, N)
        {
          if (g[j][k] == -1)
          {
            continue;
          }
          if (g[j][k] != d[k])
          {
            ok = false;
          }
        }
      }
      if (!ok)
      {
        break;
      }
    }
    if (ok)
      ans = max(ans, __builtin_popcount(i));
  }

  cout << ans << endl;
}