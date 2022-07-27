// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
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

int func(int n)
{
  if (n % 2 == 0)
  {
    return n / 2;
  }
  return 3 * n + 1;
}

int main()
{

  int s;
  cin >> s;

  vector<int> vec = {s};

  int ans;
  int a = s;

  while (true)
  {
    a = func(a);

    auto found_itr = find(vec.begin(), vec.end(), a);
    bool found = found_itr != vec.end();

    if (found)
    {
      ans = vec.size() + 1;
      break;
    }
    else
    {
      vec.push_back(a);
    }
  }

  cout << ans << endl;
}