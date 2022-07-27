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
  ll N;
  cin >> N;
  vll A(N);
  vector<pair<ll, ll>> v(N);
  rep(i, N)
  {
    cin >> A[i];
    v[i] = make_pair(A[i], i + 1);
  }
  sort(v.begin(), v.end());
  rep(i, N)
  {
    printf("%lld ", v[i].second);
  }
}