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

/*
input: 整数T n
output: vector<T> nの素因数分解結果
*/
template <typename T>
vector<T> prime_factor(T n)
{
  vector<T> ret;
  for (T i = 2; i * i <= n; i++)
  {
    T tmp = 0; // 割り切れる回数
    while (n % i == 0)
    {
      tmp++;
      n /= i;
    }
    if (tmp > 0)
      for (T j = 0; j < tmp; j++)
      {
        ret.push_back(i);
      }
  }
  if (n != 1)
    ret.push_back(n);
  return ret;
}

int main()
{
  int a = 100;
  vector<int> b = prime_factor(a);
  for (int i = 0; i < b.size(); i++)
  {
    cout << b[i] << endl;
  }
}