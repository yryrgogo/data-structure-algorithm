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
  int N, M;
  cin >> N >> M;
  vi s(N), c(N);
  vi ans(N, -1);

  rep(i, M)
  {
    cin >> s[i] >> c[i];

    if (N > 1 && s[i] == 1 && c[i] == 0)
    {
      cout << -1 << endl;
      return 0;
    }

    if (ans[s[i] - 1] == -1)
    {
      ans[s[i] - 1] = c[i];
    }
    else
    {
      if (ans[s[i] - 1] != c[i])
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  if (N == 1 && M == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  int result = 0;
  rep(i, N)
  {
    if (ans[i] == -1 && i == 0)
    {
      result += 1 * pow(10, (N - i - 1));
    }
    else if (ans[i] == -1)
    {
      continue;
    }
    else
    {
      result += ans[i] * pow(10, (N - i - 1));
    }
  }
  cout << result << endl;
}