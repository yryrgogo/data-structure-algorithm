#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)

int main()
{

  string S;
  cin >> S;

  vector<int> cnt(2, 0); // length2の配列に答えをいれる

  rep(i, S.size())
  {
    cnt[S[i] - '0']++;
  }

  int ans = min(cnt[0], cnt[1]) * 2;

  cout << ans;
}