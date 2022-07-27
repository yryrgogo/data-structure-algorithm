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

int dfs(int idx, int depth, string S, string tmp, int ans)
{
  if (depth == 0)
  {
    int diff = abs(753 - stoi(tmp));
    cout << tmp << endl;
    ans = min(diff, ans);
    return ans;
  }

  rep(idx, S.size())
  {
    if (S.size() - idx == 2 && tmp == "")
      return 1000;
    string x = tmp + S[idx];
    ans = dfs(idx + 1, depth - 1, S, x, ans);
  }

  return ans;
}

int main()
{

  string S;
  cin >> S;
  int ans = 1000;
  string tmp = "";

  rep(i, S.size() - 2)
  {
    string x = tmp + S[i] + S[i + 1] + S[i + 2];
    ans = min(abs(753 - stoi(x)), ans);
  }

  cout << ans;
}