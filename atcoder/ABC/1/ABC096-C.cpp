#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)
#define msort(v, key) sort((v).begin(), (v).end(), [](const vector<long long> &a, const vector<long long> &b) { return a[key] < b[key]; })
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main()
{
  int H, W;
  cin >> H >> W;
  // int s[H][W];
  vector<string> s(H);
  vector<vector<bool>> ANS(H, vector<bool>(W, false));

  rep(i, H)
  {
    cin >> s[i];
  }

  bool ok = true;
  rep(i, H)
  {
    rep(j, W)
    {
      if (s[i][j] == '.')
        continue;

      if (j + 1 < W)
      {
        if (i + 1 < H)
        {
          if (s[i][j] == s[i + 1][j])
          {
            ANS[i][j] = true;
            ANS[i + 1][j] = true;
          }
        }
        if (s[i][j] == s[i][j + 1])
        {
          ANS[i][j] = true;
          ANS[i][j + 1] = true;
        }

        // if (i > 0)
        // {
        //   if (s[i][j] == s[i - 1][j])
        //   {
        //     ANS[i][j] = true;
        //     ANS[i - 1][j] = true;
        //   }
        // }
      }
      else
      {
        if (i + 1 < H)
        {
          if (s[i][j] == s[i + 1][j])
          {
            ANS[i][j] = true;
            ANS[i + 1][j] = true;
          }
        }
      }
    }
  }

  rep(i, H)
  {
    rep(j, W)
    {
      if (s[i][j] == '#' && !ANS[i][j])
      {
        // printf("%lld:%lld\n", i, j);
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}