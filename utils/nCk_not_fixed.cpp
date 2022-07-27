#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

vector<ll> fact_inv, inv;

/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
void init_nCk(ll SIZE)
{
  fact_inv.resize(SIZE + 5);
  inv.resize(SIZE + 5);
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < SIZE + 5; i++)
  {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(k)
*/
long long nCk(ll n, ll k)
{
  assert(!(n < k));
  assert(!(n < 0 || k < 0));
  long long ans = 1;
  for (ll i = n; i >= n - k + 1; i--)
  {
    ans *= i;
    ans %= MOD;
  }
  return ans * fact_inv[k] % MOD;
}

int main()
{
  ll b = 2;
  init_nCk(b);

  ll a = 4;
  cout << nCk(a, b) << endl;
  a = 6;
  cout << nCk(a, b) << endl;
}