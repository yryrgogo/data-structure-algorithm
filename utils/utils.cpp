#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  unordered_set<char> a;
  string s;
  cin >> s;
  // 文字列を1文字ずつループする
  for (auto d : s)
  {
    a.insert(d);
    cout << a.count(d) << endl;
    cout << a.size() << endl;
  }
}