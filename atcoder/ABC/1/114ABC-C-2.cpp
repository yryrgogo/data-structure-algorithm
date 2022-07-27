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
string S = "753";

bool isOk(string s)
{
  return s.find("7") != string::npos && s.find("5") != string::npos && s.find("3") != string::npos;
}

int dfs(int depth, int cnt, string s, string N)
{
  if (depth == 0)
  {
    if (stoi(s) > stoi(N))
      return cnt;
    if (isOk(s))
    {
      // cout << s << endl;
      cnt++;
    }
    return cnt;
  }

  rep(i, 3)
  {
    string tmp = s + S[i];
    cnt = dfs(depth - 1, cnt, tmp, N);
  }

  return cnt;
}

int main()
{
  string N;
  cin >> N;

  int ans = 0;
  string s = "";

  repd(i, 3, N.size() + 1)
  {
    ans = dfs(i, ans, s, N);
  }

  cout << ans;
}