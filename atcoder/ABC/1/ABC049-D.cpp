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

struct UnionFind
{
  vector<ll> par, siz;

  UnionFind(ll n) : par(n, -1), siz(n, 1) {}

  ll root(ll x)
  {
    if (par[x] == -1)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(ll x, ll y)
  {
    return root(x) == root(y);
  }

  bool unite(ll x, ll y)
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

  ll size(ll x)
  {
    return siz[root(x)];
  }
};

int main()
{
  ll N, K, L;
  cin >> N >> K >> L;
  ll p[K], q[K], r[L], s[L];

  UnionFind uf1(N);
  UnionFind uf2(N);

  vll ans(N, 0);

  rep(i, K)
  {
    cin >> p[i] >> q[i];
    p[i]--;
    q[i]--;
    uf1.unite(p[i], q[i]);
  }
  rep(i, L)
  {
    cin >> r[i] >> s[i];
    r[i]--;
    s[i]--;
    uf2.unite(r[i], s[i]);
  }

  map<pair<ll, ll>, ll> mp;

  rep(i, N)
  {
    printf("%lld : %lld\n", uf1.root(i), uf2.root(i));
    mp[make_pair(uf1.root(i), uf2.root(i))]++;
  }

  rep(i, N)
  {
    cout << mp[make_pair(uf1.root(i), uf2.root(i))] << " ";
  }
}