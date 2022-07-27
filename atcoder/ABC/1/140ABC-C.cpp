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
  int A[N], B[N - 1];
  rep(i, N - 1) cin >> B[i];

  int ans = 0;
  rep(i, N)
  {
    if (i == 0)
    {
      ans += B[i];
    }
    else if (i == N - 1)
    {
      ans += B[N - 2];
    }
    else
    {
      ans += min(B[i - 1], B[i]);
    }
  }
  cout << ans << endl;
}