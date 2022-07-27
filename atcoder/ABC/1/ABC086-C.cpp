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
  ll N;
  cin >> N;
  ll t[N], x[N], y[N];
  rep(i, N) cin >> t[i] >> x[i] >> y[i];

  rep(i, N)
  {
    if (i == 0)
    {
      if (abs(x[i] + y[i]) > t[i])
      {
        cout << "No" << endl;
        return 0;
      }
      if (abs(x[i] + y[i]) % 2 != t[i] % 2)
      {
        cout << "No" << endl;
        return 0;
      }
      continue;
    }

    if (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) > (t[i] - t[i - 1]))
    {
      cout << "No" << endl;
      return 0;
    }

    if ((abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])) % 2 != (t[i] - t[i - 1]) % 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}