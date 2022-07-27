#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int H, W;
  cin >> H >> W;

  string S[H];
  rep(y, H) cin >> S[y];

  vvi yoko(H), tate(W);

  rep(y, H)
  {
    yoko[y].push_back(0);
    rep(x, W)
    {
      if (S[y][x] == '#')
      {
        yoko[y].push_back(x + 1);
      }
    }
    yoko[y].push_back(W + 1);
  }

  rep(x, W)
  {
    tate[x].push_back(0);
    rep(y, H)
    {
      if (S[y][x] == '#')
      {
        tate[x].push_back(y + 1);
      }
    }
    tate[x].push_back(H + 1);
  }

  int ans = 0;
  rep(y, H)
  {
    rep(x, W)
    {
      int ix = distance(yoko[y].begin(), lower_bound(yoko[y].begin(), yoko[y].end(), x + 1));
      int tmpYoko = (yoko[y][ix] - yoko[y][ix - 1]) - 1;
      int iy = distance(tate[x].begin(), lower_bound(tate[x].begin(), tate[x].end(), y + 1));
      int tmpTate = (tate[x][iy] - tate[x][iy - 1]) - 1;
      chmax(ans, tmpYoko + tmpTate - 1);
    }
  }

  pt(ans);
}

#else

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using Graph = vector<vector<int>>;
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
template <typename T>
inline ll gcd(T x, T y)
{
  if (y == 0)
  {
    return x;
  }
  return gcd(y, x % y);
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#endif