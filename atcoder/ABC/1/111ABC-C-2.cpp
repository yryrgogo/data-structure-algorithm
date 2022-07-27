#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

int main()
{

  int n;
  cin >> n;
  int v[n];

  rep(i, n) cin >> v[i];

  int seq0[100001] = {}, seq1[100001] = {};
  for (int i = 0; i < n; i += 2)
    ++seq0[v[i]];
  for (int i = 1; i < n; i += 2)
    ++seq1[v[i]];

  // ここでodd, evenそれぞれの先頭の数字が一致してるかどうか判定するための数字を取得する
  int i_0 = 0, i_1 = 0;
  for (int i = 1; i <= 100000; ++i)
  {
    if (seq0[i] > seq0[i_0])
      i_0 = i;
    if (seq1[i] > seq1[i_1])
      i_1 = i;
  }

  sort(seq0 + 1, seq0 + 100001, greater<int>());
  sort(seq1 + 1, seq1 + 100001, greater<int>());

  if (seq0[0] == seq1[0])
    cout << min(n - seq0[0] - seq1[1], n - seq0[1] - seq1[0]);
  else
    cout << n - seq0[0] - seq1[0];
}