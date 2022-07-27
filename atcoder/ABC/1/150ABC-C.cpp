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
  vi v(N);
  rep(i, N) v[i] = i + 1;
  vi P(N), Q(N);
  rep(i, N) cin >> P[i];
  rep(i, N) cin >> Q[i];

  // ll cnt = 1;
  // ll a, b;
  map<vector<int>, int> mp;
  do
  {
    mp[v] = mp.size();
    // bool p_ok = true;
    // bool q_ok = true;
    // rep(i, N)
    // {
    //   if (P[i] != v[i])
    //   {
    //     p_ok = false;
    //   }
    //   if (Q[i] != v[i])
    //   {
    //     q_ok = false;
    //   }
    // }
    // if (p_ok)
    // {
    //   a = cnt;
    // }
    // if (q_ok)
    // {
    //   b = cnt;
    // }

    // cnt++;
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(mp[P] - mp[Q]) << endl;
}