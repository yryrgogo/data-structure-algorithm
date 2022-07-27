#if !__INCLUDE_LEVEL__

#include __FILE__

int A, B, C, D, E, F;
double max_r = -1;
vi ans(2, 0);

void dfs(int w)
{
  if (w > F)
  {
    return;
  }

  // add sugar
  int N = w / 100 * E;

  vi S(N + 1, 0);
  rep(i, N + 1)
  {
    rep(j, N + 1)
    {
      int s = i * C + j * D;
      if (s <= N)
      {
        S[s] = 1;
      }
    }
  }

  rep(s, N + 1)
  {
    if (S[s] == 0)
      continue;

    if (w > 0 && w + s <= F && s <= w)
    {
      double r = (double)s * 100 / (w + s);

      if (r >= max_r)
      {
        ans[0] = w + s;
        ans[1] = s;
        max_r = r;
      }
    }
  }

  dfs(w + 100 * A);
  dfs(w + 100 * B);

  return;
}

int main()
{
  cin >> A >> B >> C >> D >> E >> F;

  dfs(0);

  // vi x(F + 1, 0);
  // vi y(F + 1, 0);
  // rep(i, F)
  // {
  //   rep(j, F)
  //   {
  //     int s = (i * C + j * D);
  //     if (s <= F)
  //     {
  //       // if (s == 934)
  //       // {
  //       //   pt(i);
  //       //   pt(j);
  //       // }
  //       y[s] = 1;
  //     }

  //     int w = (100 * A * i + 100 * B * j);
  //     if (w <= F && w > 0)
  //     {
  //       x[w] = 1;
  //     }
  //   }
  // }

  // double max_r = 0;
  // rep(i, F)
  // {
  //   if (x[i] == 0)
  //     continue;
  //   rep(j, F)
  //   {
  //     if (y[j] == 0 || i + j == 0 || i + j > F)
  //       continue;

  //     if ((i / 100) * E < j)
  //       continue;

  //     double ratio = (double)j / (i + j);
  //     if (max_r < ratio)
  //     {
  //       max_r = ratio;
  //       ans[0] = i + j;
  //       ans[1] = j;
  //     }
  //   }
  // }

  printf("%d %d", ans[0], ans[1]);
}

#else

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

#endif