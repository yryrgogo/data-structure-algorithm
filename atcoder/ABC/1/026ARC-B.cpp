// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int main()
{

  ll N;
  cin >> N;
  vector<ll> divs;
  for (ll i = 1; i <= sqrt((double)N); i++)
  {
    if (N % i == 0)
    {
      if (N == i)
        continue;
      divs.push_back(i);
      if (N / i != N && i != N / i)
        divs.push_back(N / i);
    }
  }
  ll ans = 0;
  for (ll i = 0; i < divs.size(); i++)
  {
    ans += divs[i];
  }
  if (ans == N)
    cout << "Perfect" << endl;
  else if (ans > N)
    cout << "Abundant" << endl;
  else if (ans < N)
    cout << "Deficient" << endl;
}