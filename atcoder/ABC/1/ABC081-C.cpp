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
  int N, K;
  cin >> N >> K;

  int cnt[200010] = {};
  rep(i, N)
  {
    int a;
    cin >> a;
    cnt[a - 1]++;
  }
  sort(cnt, cnt + N);
  rep(i, N - K)
  {
    cout << cnt[i] << endl;
  }
  // vi A(N);

  // unordered_map<int, int> mp;

  // rep(i, N)
  // {
  //   cin >> A[i];
  //   mp[A[i]]++;
  // }

  // if (mp.size() <= K)
  // {
  //   cout << 0 << endl;
  //   return 0;
  // }

  // vector<vector<ll>> vp;

  // for (auto p : mp)
  // {
  //   vp.push_back({p.first, p.second});
  // }

  // msort(vp, 1);

  // int ans = 0;
  // int cnt = 0;
  // rep(i, vp.size())
  // {
  //   ans += vp[i][1];
  //   cnt++;
  //   if (vp.size() - cnt <= K)
  //   {
  //     break;
  //   }
  // }

  // cout << ans << endl;
}
