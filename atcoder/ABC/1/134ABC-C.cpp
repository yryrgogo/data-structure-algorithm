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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &alpha, const vector<long long> &beta) { return alpha[key] < beta[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int N;
  cin >> N;
  vi A(N), B(N);
  rep(i, N) cin >> A[i];
  B = A;
  sort(A.begin(), A.end());

  rep(i, N)
  {
    if (A[(N - 1)] == B[i])
    {
      cout << A[(N - 2)] << endl;
    }
    else
    {
      cout << A[(N - 1)] << endl;
    }
  }
}