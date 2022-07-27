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
  vll x(N);
  rep(i, N) cin >> x[i];
  vll y = x;
  sort(x.begin(), x.end());

  ll ans1 = x[(int)(N / 2) - 1];
  ll ans2 = x[(int)(N / 2)];

  if (ans1 == ans2)
  {
    cout << ans1 << endl;
    return 0;
  }

  rep(i, N)
  {
    if (y[i] < ans2)
    {
      cout << ans2 << endl;
    }
    else
    {
      cout << ans1 << endl;
    }
  }
}