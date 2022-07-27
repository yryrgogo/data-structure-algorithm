#if !__INCLUDE_LEVEL__

#include __FILE__

int main()
{
  string S, T;
  cin >> S >> T;

  vector<string> anss;

  // T との一致をみる
  rep(i, T.size())
  {
    rep(j, S.size())
    {
      bool ok = true;
      if (T[i] == S[j])
      {
        int before = i;
        int after = T.size() - i - 1;

        if (j - before < 0)
          continue;
        // 前方
        repd(k, 1, before + 1)
        {
          if (S[j - k] == '?')
            continue;
          if (T[i - k] != S[j - k])
          {
            // 前方に組み込めず
            ok = false;
            break;
          }
        }
        if (!ok)
          continue;

        if (j + after >= S.size())
          continue;

        // 後方
        repd(k, 1, after + 1)
        {
          if (S[j + k] == '?')
            continue;
          if (T[i + k] != S[j + k])
          {
            ok = false;
            break;
          }
        }
        if (!ok)
          continue;
      }
      else
      {
        ok = false;
      }

      // T を組み込める場合
      if (ok)
      {
        string s = S;
        s[j] = T[i];
        int before = i;
        int after = T.size() - i - 1;
        repd(k, 1, before + 1)
        {
          s[j - k] = T[i - k];
        }
        repd(k, 1, after + 1)
        {
          s[j + k] = T[i + k];
        }
        rep(k, s.size())
        {
          if (s[k] == '?')
            s[k] = 'a';
        }
        anss.push_back(s);
      }
    }
  }

  // ? にそのまま埋める
  int cnt = 0;
  rep(i, S.size())
  {
    if (S[i] == '?')
      cnt++;
    else
      cnt = 0;

    if (cnt == T.size())
    {
      string s = S;
      rep(j, T.size())
      {
        s[i - T.size() + 1 + j] = T[j];
      }
      rep(j, s.size())
      {
        if (s[j] == '?')
          s[j] = 'a';
      }
      anss.push_back(s);
      cnt = 0;
    }
  }

  if (anss.size() > 0)
  {
    sort(anss.begin(), anss.end());
    string ans = anss[0];
    cout << ans << endl;
  }
  else
  {
    cout << "UNRESTORABLE" << endl;
  }
}

#else

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
template <typename T>
void pt(T val)
{
  cout << val << "\n";
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#endif