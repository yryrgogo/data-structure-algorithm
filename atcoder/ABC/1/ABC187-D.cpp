#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  ll N;
  cin >> N;
  vll A(N), B(N);
  // vector<pair<ll, ll>> C(N);
  vector<vector<ll>> C(N);

  ll sa = 0, sb = 0;
  ll ans = 0;

  rep(i, N)
  {
    cin >> A[i] >> B[i];
    sa += A[i];
    sb += B[i];
    // C[i] = make_pair(A[i] + B[i], i);
    C[i] = {A[i] + A[i] + B[i], B[i], i};
    // C[i] = make_pair(A[i] + B[i] + B[i], i);
  }
  // sort(C.rbegin(), C.rend());
  msort(C, 1);
  msort(C, 0);

  ll sum = 0;
  // ll half = (sa + sb) / 2;
  rep(i, N)
  {
    ll idx = N - 1 - i;
    sum += A[C[idx][2]] + B[C[idx][2]];
    sa -= A[C[idx][2]];
    // cout << C[i][2] << " : " << sum << " : " << sa << endl;
    if (sum > sa)
    {
      ans += i + 1;
      break;
    }
    // pt(C[idx][0]);
  }
  pt(ans);
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