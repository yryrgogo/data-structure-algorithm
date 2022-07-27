// #include <bits/stdc++.h>
#include <iostream>
#include <list>
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
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  vector<int> vec = {A, B, C, D, E};

  int max = -1;
  for (auto i : {A, B, C, D, E})
  {
    string s = to_string(i);
    int num = s[s.length() - 1] - '0';

    if (num != 0 && (10 - num) > max)
    {
      max = (10 - num);

      for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
      {
        if (*it == i)
        {
          vec.erase(it);
          break;
        }
      }
      vec.push_back(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < vec.size() - 1; i++)
  {
    int next = vec[i];
    if (next % 10 == 0)
    {
      ans += next;
    }
    else
    {
      ans += 10 - (next % 10) + next;
    }
  }
  ans += vec[vec.size() - 1];

  cout << ans << endl;
}