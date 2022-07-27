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
  vll A(N + 2);
  A[0] = 0;
  rep(i, N) cin >> A[i + 1];
  A[N + 1] = 0;

  ll sum = 0;
  rep(i, N + 1)
  {
    sum += abs(A[i] - A[i + 1]);
  }

  rep(i, N)
  {
    if ((A[i + 1] - A[i]) * (A[i + 2] - A[i + 1]) > 0)
    {
      cout << sum << endl;
    }
    else
    {
      cout << sum - min(abs(A[i] - A[i + 1]), abs(A[i + 1] - A[i + 2])) * 2 << endl;
    }
  }
}