#if !__INCLUDE_LEVEL__

#include __FILE__

ll calc(ll A)
{
  ll ans = 0;
  rep(i, 50)
  {
    // loopの大きさは2^桁乗
    ll loop = (1LL << (i + 1));
    ll cnt = (A / loop) * (loop / 2);
    cnt += max(0LL, (A % loop) - (loop / 2));

    if (cnt % 2 == 1)
    {
      ans += 1LL << i;
    }
  }

  return ans;
}

int main()
{
  ll A, B;
  cin >> A >> B;

  int b = log2(B) + 1;
  A++;
  B++;

  ll ans = 0;
  rep(i, b)
  {
    ll ap = 0;
    ll an = 0;
    ll ac = 0;
    if (A >= (ll)pow(2, i))
    {
      if (A % (ll)pow(2, i) == 0)
      {
        ap = A / (ll)pow(2, i);
        an = 0;
      }
      else
      {
        ap = A / (ll)pow(2, i) + 1;
        an = A % (ll)pow(2, i);
      }

      if (ap % 2 == 0 && an % 2 == 1)
        ac = 1;

      // A自身の対象桁に1が立っている場合は二重カウントしてしまうため、偶奇をずらすために+1する
      if (ap % 2 == 0)
        ac++;
    }

    ll bp;
    ll bn;
    if (B % (ll)pow(2, i) == 0)
    {
      bp = B / (ll)pow(2, i);
      bn = 0;
    }
    else
    {
      bp = B / (ll)pow(2, i) + 1;
      bn = B % (ll)pow(2, i);
    }

    ll bc = 0;
    if (bp % 2 == 0 && bn % 2 == 1)
      bc = 1;

    // 1桁目のみ違う
    if (i == 0)
    {
      ac = (A / 2) % 2;
      bc = (B / 2) % 2;

      if (ap % 2 == 0)
        ac++;
    }

    // printf("%lld : %lld : %lld : %lld\n", ap, ac, bp, bc);
    // pt(ac + bc);
    ans += (ll)pow(2, i) * ((ac + bc) % 2);
  }

  cout << ans << endl;
}

#else

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
template <typename T>
void pt(T val)
{
  cout << val << "\n";
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#endif