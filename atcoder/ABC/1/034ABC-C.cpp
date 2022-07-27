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

vector<ll> fact_inv, inv, Com;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(int n, int SIZE)
{
  fact_inv.resize(SIZE + 5);
  inv.resize(SIZE + 5);
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < SIZE + 5; i++)
  {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }
  Com.resize(SIZE + 5);
  Com[0] = 1;
  for (int i = 1; i < SIZE + 5; i++)
  {
    Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
  }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
ll nCk(int k)
{
  assert(!(k < 0));
  return Com[k];
}

int W, H;
ll ans = 0;

int main()
{

  cin >> W >> H;

  int a1 = W + H - 2;
  int b1 = W - 1;

  ll ans = 0;
  init_nCk(a1, b1);
  ans += nCk(b1);
  cout << ans << endl;
}