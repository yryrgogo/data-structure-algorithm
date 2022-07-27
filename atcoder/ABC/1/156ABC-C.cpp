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
  int N;
  cin >> N;
  vi x(N);
  rep(i, N) cin >> x[i];

  // ll ans = INF;
  // rep(i, 100)
  // {
  //   ll dist = 0;
  //   rep(j, N)
  //   {
  //     dist += pow(x[j] - (i + 1), 2);
  //   }
  //   ans = min(ans, dist);
  // }
  // cout << ans << endl;

  int sum = accumulate(x.begin(), x.end(), 0);
  int ans = 0;
  int point = round((double)sum / N);

  rep(i, N)
  {
    ans += pow(x[i] - point, 2);
  }
  cout << ans << endl;
}