#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &alpha, const vector<long long> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  ll A, B, X;
  cin >> A >> B >> X;
  ll l = 0, r = 1000000001;

  auto keta = [&](ll c) {
    return (int)(log10(c) + 1);
  };

  auto f = [&](ll c) {
    return A * c + B * keta(c);
  };

  while (r - l > 1)
  {
    ll c = (l + r) / 2;
    if (f(c) <= X)
      l = c;
    else
      r = c;
  }
  cout << l << endl;

  // ll ans = 0;
  // repd(i, 1, 11)
  // {
  //   ll tmp = (X - (B * i)) / A;
  //   int len = log10(tmp) + 1;
  //   if (len == i)
  //   {
  //     ans = max(ans, tmp);
  //   }
  //   if (tmp >= 1000000000 && len >= 10)
  //   {
  //     printf("%d", 1000000000);
  //     return 0;
  //   }
  // }
  // cout << ans << endl;
}