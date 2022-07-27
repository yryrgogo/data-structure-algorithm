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
  vector<int> par, siz;

  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int x)
  {
    if (par[x] == -1)
      return x;
    else
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

// int main()
// {
//   int N, M;
//   cin >> N >> M;
//   vvi edge(M);
//   int ans = 0;

//   rep(i, M)
//   {
//     int a, b;
//     cin >> a >> b;
//     a--;
//     b--;
//     edge[i].push_back(a);
//     edge[i].push_back(b);
//   }

//   rep(i, M)
//   {
//     UnionFind uf(N);
//     rep(j, M)
//     {
//       if (i == j)
//         continue;

//       int a = edge[j][0];
//       int b = edge[j][1];
//       uf.unite(a, b);
//     }

//     if (uf.size(0) != N)
//       ans++;
//   }

//   cout << ans << endl;
// }

int N, M;
bool graph[60][60];
// グラフを辿ったというメモ
bool vis[60];

void dfs(int x)
{
  // 一度通った頂点はもう通らなくてよいため
  if (vis[x])
    return;

  vis[x] = true;
  rep(i, N)
  {
    if (graph[x][i])
    {
      dfs(i);
    }
  }
}

int main()
{
  cin >> N >> M;
  int a[M], b[M];
  int ans = 0;

  rep(i, M)
  {
    cin >> a[i] >> b[i];
    graph[a[i] - 1][b[i] - 1] = true;
    graph[b[i] - 1][a[i] - 1] = true;
  }

  rep(i, M)
  {
    rep(j, N) vis[j] = false;
    graph[a[i] - 1][b[i] - 1] = false;
    graph[b[i] - 1][a[i] - 1] = false;

    // 辿った場所に印をつける操作
    dfs(0);

    rep(j, N)
    {
      if (!vis[j])
      {
        ans++;
        break;
      }
    }

    graph[a[i] - 1][b[i] - 1] = true;
    graph[b[i] - 1][a[i] - 1] = true;
  }
  cout << ans << endl;
}