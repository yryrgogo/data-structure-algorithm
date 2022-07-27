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

// Union-Find
struct UnionFind
{
  vector<int> par, siz;

  // initialize
  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int x)
  {
    if (par[x] == -1)
      return x;
    else
      // 再帰で親の親を返しつつ経路圧縮を行う（途中のノードの親を全てに根に付け替える）
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y)
  {
    return root(x) == root(y);
  }

  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (siz[x] < siz[y])
      swap(x, y);

    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x)
  {
    return siz[root(x)];
  }
};
