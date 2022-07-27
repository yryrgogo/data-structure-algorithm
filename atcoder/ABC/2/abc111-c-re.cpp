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
  int MAX = 100001;
  int N;
  cin >> N;
  vector<ll> o(MAX, 0);
  vector<ll> e(MAX, 0);

  rep(i, N)
  {
    int x;
    cin >> x;

    if (i % 2 == 0)
    {
      e[x]++;
    }
    else
    {
      o[x]++;
    }
  }

  pair<ll, ll> fe = make_pair(0, 0);
  pair<ll, ll> fo = make_pair(0, 0);
  pair<ll, ll> fe2 = make_pair(0, 0);
  pair<ll, ll> fo2 = make_pair(0, 0);

  rep(i, MAX)
  {
    if (fe.first < e[i])
    {
      fe2.first = fe.first;
      fe2.second = fe.second;

      fe.first = e[i];
      fe.second = i;
    }

    if (fo.first < o[i])
    {
      fo2.first = fo.first;
      fo2.second = fo.second;

      fo.first = o[i];
      fo.second = i;
    }

    // これだけではダメ。なぜなら fe, fo が前に捨てた値が2番目に大きな値となる可能性があるが、この実装ではそれをサルベージできない
    if (fe2.first < e[i] and i != fe.second)
    {
      fe2.first = e[i];
      fe2.second = i;
    }
    if (fo2.first < o[i] and i != fo.second)
    {
      fo2.first = o[i];
      fo2.second = i;
    }
  }

  // same max
  if (fe.second == fo.second)
  {
    // ll se = 0;
    // ll so = 0;
    // rep(i, MAX)
    // {
    //   if (se < e[i] and i != fe.second)
    //   {
    //     se = e[i];
    //   }

    //   if (so < o[i] and i != fo.second)
    //   {
    //     so = o[i];
    //   }
    // }
    // cout << min(N - fe.first - so, N - fo.first - se) << endl;
    cout << min(N - fe.first - fo2.first, N - fo.first - fe2.first) << endl;
  }
  else
  {
    cout << min(N - fe.first - fo.first, N - fo.first - fe.first) << endl;
  }
}