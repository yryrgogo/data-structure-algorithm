#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
  ll N, K;
  cin >> N >> K;

  ll X[N];
  ll zero = -1;
  ll maxIdx = 0;
  for (ll i = 0; i < N; i++)
  {
    cin >> X[i];
    if (zero == -1 && X[i] >= 0)
      zero = i;
    maxIdx = i;
  }

  if (zero == -1)
  {
    cout << abs(X[maxIdx - K + 1]);
    return 0;
  }
  if (zero == 0)
  {
    cout << abs(X[K - 1]);
    return 0;
  }

  ll left = 0, right = 0;
  if (zero <= K)
  {
    left = 0;
  }
  else if (zero > K)
  {
    left = zero - K;
  }
  right = zero + K - 1;

  // cout << "zero: " << zero << " left: " << left << " right: " << right << endl;

  ll ans = 1000000000;
  for (ll i = 0; i < (right - left + 1 - K + 1); i++)
  {
    ll sum1 = 0;
    ll sum2 = 0;
    if (left + i + K - 1 > maxIdx)
      break;
    sum1 += abs(X[left + i]) * 2 + X[left + i + K - 1];
    sum2 += abs(X[left + i]) + X[left + i + K - 1] * 2;
    ll sum = min(sum1, sum2);
    ans = min(ans, sum);
  }

  cout << ans;

  return 0;
}