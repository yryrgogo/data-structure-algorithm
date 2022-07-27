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

int main()
{
  int N;
  cin >> N;
  vvi to(N), cost(N);

  rep(i, N - 1)
  {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    to[a].push_back(b);
    cost[a].push_back(w);
    to[b].push_back(a);
    cost[b].push_back(w);

    vi ans(N, -1);
    queue<int> q;
    ans[0] = 0;
    q.push(0);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      rep(i, to[v].size())
      {
        int u = to[v][i];
        int w = cost[v][i];
        if (ans[u] != -1)
          continue;
        ans[u] = (ans[v] + w) % 2;
        q.push(u);
      }
    }
  }
}