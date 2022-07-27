#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int add_rec(int n)
{
  if (n == 0)
    return 0;

  return n + add_rec(n - 1); // ここがStreamで連鎖していくイメージ
}

int fibo(int n)
{
  // base case
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  // recursive call
  return fibo(n - 1) + fibo(n - 2);
}

long long fiboMemo(int n, vector<long long> &memo)
{
  // base case
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  // check memo
  if (memo[n] != -1)
    return memo[n];

  // recursive call and memo
  return memo[n] = fiboMemo(n - 1, memo) + fiboMemo(n - 2, memo);
}

bool partOfAdd(int i, int x, const vector<int> &a)
{
  // base case
  if (i == 0)
  {
    if (x == 0)
      return true;
    else
      return false;
  }

  // a[i - 1]を選ばない場合(func(i-1, x, a)がOKならOK)
  if (partOfAdd(i - 1, x, a))
    return true;

  // a[i - 1]を選ぶ場合（func(i - 1, x - a[i - 1], a)がOKならOK）
  if (partOfAdd(i - 1, x - a[i - 1], a))
    return true;

  // どっちもダメだったらダメ
  return false;
}

int main()
{

  // メモ化フィボナッチ
  // vector<long long> memo(50, -1);
  // cout << fiboMemo(49, memo) << endl;

  // 部分和問題
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int X;
  cin >> X;

  // recursive call
  if (partOfAdd(n, X, a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}