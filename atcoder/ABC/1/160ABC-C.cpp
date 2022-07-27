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
  ll K, N;
  cin >> K >> N;
  vll A(N);
  vll D;
  rep(i, N)
  {
    cin >> A[i];
    if (i > 0)
    {
      D.push_back(A[i] - A[i - 1]);
    }
  }

  cout << K - max(*max_element(D.begin(), D.end()), (K - A[A.size() - 1] + A[0])) << endl;
}