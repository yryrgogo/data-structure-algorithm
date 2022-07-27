#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  int h, w, k;
  cin >> h >> w >> k;
  string c[h];
  rep(i, h) cin >> c[i];

  int ans = 0;

  rep(is, 1 << h) rep(js, 1 << w)
  {
    int cnt = 0;
    rep(i, h) rep(j, w)
    {
      if (is >> i & 1)
        continue;
      if (js >> j & 1)
        continue;
      if (c[i][j] == '#')
        cnt++;
    }

    if (cnt == k)
      ans++;
  }

  pt(ans);

  return 0;
}

// void dfs(string dh, string dw)
// {
//   if (dh.size() == h && dw.size() == w)
//   {
//     int cnt = 0;

//     rep(i, dh.size())
//     {
//       if (dh[i] - '0')
//         cnt += get_black_row(i + 1);
//     }
//     // pt(cnt);
//     rep(j, dw.size())
//     {
//       if (dw[j] - '0')
//         cnt += get_black_col(j + 1);
//     }
//     // pt(cnt);
//     rep(i, dh.size()) rep(j, dw.size())
//     {
//       if (dh[i] - '0' && dw[j] - '0')
//         cnt -= get_black_cross(i + 1, j + 1);
//     }
//     // pt(cnt);

//     int rem = b_cnt - cnt;
//     if (rem == k)
//     {
//       // pt(cnt);
//       // pt(b_cnt);
//       // cout << dh << " : " << dw << " : " << cnt << endl;
//       ans++;
//     }

//     return;
//   }

//   if (dh.size() < h && dw.size() < w)
//   {
//     dfs(dh + '1', dw + '1');
//     dfs(dh + '0', dw + '0');
//     dfs(dh + '0', dw + '1');
//     dfs(dh + '1', dw + '0');
//   }
//   else if (dh.size() < h && dw.size() == w)
//   {
//     dfs(dh + '1', dw);
//     dfs(dh + '0', dw);
//   }
//   else if (dh.size() == h && dw.size() < w)
//   {
//     dfs(dh, dw + '1');
//     dfs(dh, dw + '0');
//   }
// }

// int main()
// {
//   cin >> h >> w >> k;
//   repd(i, 1, h + 1) repd(j, 1, w + 1)
//   {
//     cin >> c[i][j];
//     if (c[i][j] == '#')
//       b_cnt++;
//   }

//   string dh = "", dw = "";
//   dfs(dh, dw);
//   pt(ans);
// }

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