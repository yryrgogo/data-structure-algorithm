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
  ll N, M;
  cin >> N >> M;
  ll p[M];
  string s[M];
  rep(i, M) cin >> p[i] >> s[i];

  vll v_ac(N, 0), v_wa(N, 0);
  ll ac = 0;
  ll wa = 0;
  rep(i, M)
  {
    if (v_ac[p[i] - 1])
    {
      continue;
    }
    else
    {
      if (s[i] == "AC")
      {
        v_ac[p[i] - 1] = 1;
        ac++;
      }
      else
      {
        v_wa[p[i] - 1]++;
      }
    }
  }

  rep(i, N)
  {
    if (v_ac[i] == 1)
    {
      wa += v_wa[i];
    }
  }

  printf("%lld %lld", ac, wa);
}