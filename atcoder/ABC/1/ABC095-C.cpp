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
  ll A, B, C, X, Y, ans;
  cin >> A >> B >> C >> X >> Y;

  if (2 * C < (A + B))
  {
    ll half = min(X, Y);
    ll p = half * C * 2;

    // printf("%lld:%lld\n", half, ans);

    ans = p + ((X - half) * A) + ((Y - half) * B);
    ans = min(ans, p + ((X - half) * C * 2) + ((Y - half) * C * 2));
    ans = min(ans, p + ((X - half) * A) + ((Y - half) * C * 2));
    ans = min(ans, p + ((X - half) * C * 2) + ((Y - half) * B));
  }
  else
  {
    ll half = 0;
    ans = ((X - half) * A) + ((Y - half) * B);
  }

  cout << ans << endl;
}