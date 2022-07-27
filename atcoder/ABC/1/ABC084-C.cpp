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
  int N;
  cin >> N;
  int C[N], S[N], F[N];
  rep(i, N - 1)
  {
    cin >> C[i] >> S[i] >> F[i];
  }

  vi ans;
  rep(s, N)
  {
    if (s == N - 1)
    {
      ans.push_back(0);
      continue;
    }

    int t[N + 1];
    t[s + 1] = S[s] + C[s];
    repd(cur, s + 1, N - 1)
    {
      if (t[cur] > S[cur])
      {
        t[cur + 1] = ceil((double)(t[cur] - S[cur]) / F[cur]) * F[cur] + S[cur] + C[cur];
      }
      else
      {
        t[cur + 1] = S[cur] + C[cur];
      }
    }
    ans.push_back(t[N - 1]);
  }

  rep(i, N - 1)
  {
    cout << ans[i] << endl;
  }
  cout << 0 << endl;
}