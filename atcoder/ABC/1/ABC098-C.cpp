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
  ll N;
  string S;
  cin >> N >> S;
  vll A(N, 0);
  rep(i, N)
  {
    if (S[i] == 'E')
    {
      if (i == 0)
      {
        A[i]++;
      }
      else
      {
        A[i] = A[i - 1] + 1;
      }
    }
    else
    {
      if (i == 0)
        continue;
      A[i] = A[i - 1];
    }
  }

  ll ans = INF;
  rep(i, N)
  {
    if (i == 0)
    {
      ans = min(ans, A[N - 1] - A[i]);
      continue;
    }
    ans = min(ans, (A[N - 1] - A[i]) + (i - A[i - 1]));
  }
  cout << ans << endl;
}