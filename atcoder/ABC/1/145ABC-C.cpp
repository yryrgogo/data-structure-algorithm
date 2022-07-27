#include <bits/stdc++.h>
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

double ans = 0;
int N;
vi x, y;

void print(const std::vector<int> &v)
{
  for_each(v.begin(), v.end(), [](int x) {
    cout << x << " ";
  });
  cout << std::endl;
}

int main()
{
  cin >> N;
  vi P(N);
  rep(i, N)
  {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
    P[i] = i + 1;
  }

  int perm = 1;
  rep(i, N)
  {
    perm *= (i + 1);
  }
  int X = 1;
  rep(i, N - 1)
  {
    X *= (i + 1);
  }
  X *= 2;

  rep(i, N)
  {
    rep(j, N)
    {
      if (i == j || i > j)
        continue;
      double len = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
      ans += len;
    }
  }

  printf("%.12f", (ans * X) / perm);

  // vvi X(N, vi(N, 0)), Y(N, vi(N, 0));

  // do
  // {
  //   rep(i, N - 1)
  //   {
  //     if (X[P[i] - 1][P[i + 1] - 1] == 0)
  //     {
  //       X[P[i] - 1][P[i + 1] - 1] = pow(x[P[i] - 1] - x[P[i + 1] - 1], 2);
  //     }
  //     if (Y[P[i] - 1][P[i + 1] - 1] == 0)
  //     {
  //       Y[P[i] - 1][P[i + 1] - 1] = pow(y[P[i] - 1] - y[P[i + 1] - 1], 2);
  //     }
  //     double len = sqrt(X[P[i] - 1][P[i + 1] - 1] + Y[P[i] - 1][P[i + 1] - 1]);
  //     ans += len / perm;
  //   }
  // } while (next_permutation(P.begin(), P.end()));

  // printf("%.12f", ans);
}