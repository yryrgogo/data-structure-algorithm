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
template <typename T>
void pt(T val)
{
  cout << val << "\n";
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int benefit()
{

  return 0;
}

int main()
{
  int N;
  cin >> N;

  ll F[N][10];
  ll P[N][11];

  rep(i, N)
  {
    rep(j, 10)
    {
      cin >> F[i][j];
    };
  };

  rep(i, N)
  {
    rep(j, 11)
    {
      cin >> P[i][j];
    };
  };

  ll ans = -1 * INF;
  // ll s = 0;
  rep(i, 1 << 10)
  {
    if (i == 0)
      continue;

    // 各店舗との重複すう
    vll S(N, 0);

    rep(j, 10)
    {
      if (i & 1 << j)
      {
        // j==時間帯番号
        rep(k, N)
        {
          // jの時間帯で営業している店舗
          if (F[k][j] == 1)
          {
            S[k]++;
            // s = max(S[k], s);
          }
        }
      }
    }

    ll b = 0;
    rep(k, N)
    {
      b += P[k][S[k]];
    }
    // if (b == 21)
    // {
    //   rep(k, N)
    //   {
    //     cout << k << ":" << S[k] << ":" << P[k][S[k]] << endl;
    //   }
    // }
    ans = max(ans, b);
  }

  // cout << s << endl;
  cout << ans << endl;
}