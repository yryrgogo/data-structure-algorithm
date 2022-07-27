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
  vll par, siz;

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
  ll N, M;
  cin >> N >> M;
  ll A[M], B[M];
  rep(i, M)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  ll sum = N * (N - 1) / 2;

  vll ans = {sum};

  UnionFind uf(N);
  for (int i = M - 1; i >= 1; i--)
  {
    ll cnt = 0;

    if (uf.root(A[i]) != uf.root(B[i]))
    {
      ll a = uf.size(A[i]);
      ll b = uf.size(B[i]);

      sum = max((ll)0, sum - (a * b));
      ans.push_back(sum);
    }
    else
    {
      ans.push_back(sum);
    }

    uf.unite(A[i], B[i]);
  }

  rep(i, M)
  {
    cout << ans[M - i - 1] << endl;
  }
}