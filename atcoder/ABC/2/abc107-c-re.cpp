// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> r;
  vector<int> l;

  rep(i, N)
  {
    int x;
    cin >> x;
    if (x == 0)
    {
      K--;
    }

    if (x > 0)
    {
      r.push_back(x);
    }
    else
    {
      l.push_back(x);
    }
  }

  sort(r.begin(), r.end());
  sort(l.begin(), l.end(), std::greater<int>());

  if (K == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  ll ans = INF;

  rep(i, K + 1)
  {
    ll tmp = 0;
    int k = 0;

    // printf("%lld : %lld\n", i - 1, K - i - 1);

    if (i - 1 >= 0 && r.size() >= i)
    {
      tmp += r[i - 1];
      k += i;
    }

    if (K - i - 1 >= 0 && l.size() >= K - i)
    {
      tmp += abs(l[K - i - 1]) * 2;
      k += K - i;
    }

    if (k >= K)
    {
      // printf("0 %d : %d : %lld\n", k, i, ans);
      ans = min(ans, tmp);
    }

    tmp = 0;
    k = 0;
    if (i - 1 >= 0 && l.size() >= i)
    {
      tmp += abs(l[i - 1]);
      k += i;
    }

    if (K - i - 1 >= 0 && r.size() >= K - i)
    {
      tmp += abs(r[K - i - 1]) * 2;
      k += K - i;
    }

    if (k >= K)
    {
      // printf("1 %d : %d : %lld\n", k, i, ans);
      ans = min(ans, tmp);
    }
  }

  cout << ans << endl;
}