#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

ll evaluation(ll N, ll b, ll A[])
{

  ll acc = 0;
  for (ll i = 0; i < N; i++)
  {
    acc += abs((A[i] - (i + 1)) - b);
  }

  return acc;
}

bool compare(ll i, ll j)
{
  if (i < j)
  {
    return true;
  }
  return false;
}

int main()
{

  ll N;

  cin >> N;

  ll A[N];
  vector<ll> B;

  for (ll i = 0; i < N; i++)
  {
    cin >> A[i];
    B.push_back(A[i] - (i + 1));
  }
  sort(B.begin(), B.end(), compare);

  ll mid = (N - 1) / 2;
  ll b = B[mid];

  cout << evaluation(N, b, A);

  return 0;
}