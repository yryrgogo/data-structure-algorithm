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

int main()
{
  int c[3][3];
  rep(i, 3) rep(j, 3) cin >> c[i][j];

  rep(a0, 101)
  {
    rep(b0, 101)
    {
      rep(a1, 101)
      {
        rep(b1, 101)
        {
          int d[3];
          int e[3];
          d[0] = a0;
          d[1] = a1;
          e[0] = b0;
          e[1] = b1;

          int cnt = 0;
          rep(i, 2)
          {
            rep(j, 2)
            {
              if (c[i][j] == d[i] + e[j])
              {
                cnt++;
              }
            }
          }
          if (cnt < 4)
          {
            continue;
          }

          int b2 = c[1][2] - a1;
          int a2 = c[2][1] - b1;
          d[2] = a2;
          e[2] = b2;

          bool ok = true;
          rep(i, 3)
          {
            if (c[2][i] != a2 + e[i] || c[i][2] != b2 + d[i])
            {
              ok = false;
            }
          }

          if (ok)
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
}