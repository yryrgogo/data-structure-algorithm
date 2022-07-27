#if !__INCLUDE_LEVEL__

#include __FILE__

ll N, M;

vi bfs(const Graph &G, int s)
{
  vi dist(N + 1, -1);
  queue<int> que;

  dist[s] = 0;
  que.push(s);

  while (!que.empty())
  {
    int v = que.front();
    que.pop();

    for (int x : G[v])
    {
      if (dist[x] != -1)
        continue;

      dist[x] = dist[v] + 1;
      que.push(x);
    }
  }

  return dist;
}

int main()
{
  cin >> N >> M;

  Graph G(200001);

  rep(i, M)
  {
    ll a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);

    G[a].push_back(b);
  }

  vi dist = bfs(G, 1);

  dist[N] == 2 ? pt("POSSIBLE") : pt("IMPOSSIBLE");

  // ll a[M], b[M];

  // map<ll, ll> s;
  // map<ll, ll> g;

  // rep(i, M)
  // {
  //   ll a, b;
  //   cin >> a >> b;

  //   if (a > b)
  //     swap(a, b);

  //   if (a == 1)
  //   {
  //     s[b] = a;
  //   }
  //   else if (b == N)
  //   {
  //     g[a] = b;
  //   }
  // }

  // bool ok = false;
  // // repd(i, 2, N)
  // for (auto p : s)
  // {
  //   // if (s[i] && g[i])
  //   if (g[p.first])
  //   {
  //     ok = true;
  //   }
  // }

  // vll nodes;
  // vll goals;

  // rep(i, M)
  // {
  //   ll a, b;
  //   cin >> a >> b;

  //   if (a > b)
  //     swap(a, b);

  //   if (a == 1 && b != N)
  //   {
  //     nodes.push_back(b);
  //   }
  //   else if (b == N && a != 1)
  //   {
  //     goals.push_back(a);
  //   }
  // }

  // if (M == 1)
  // {
  //   pt("IMPOSSIBLE");
  //   return 0;
  // }

  // sort(goals.begin(), goals.end());

  // bool ok = false;
  // rep(i, nodes.size())
  // {
  //   int g = binary_search(goals.begin(), goals.end(), nodes[i]);
  //   if (g == 1)
  //   {
  //     ok = true;
  //     break;
  //   }
  // }

  // ok ? pt("POSSIBLE") : pt("IMPOSSIBLE");
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