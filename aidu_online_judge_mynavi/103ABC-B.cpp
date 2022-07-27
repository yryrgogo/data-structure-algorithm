#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  int LEN = S.length();

  for (int i = 0; i < LEN; i++)
  {

    char L = S[S.size() - 1];
    S = L + S;
    S.pop_back();

    if (S == T)
    {
      cout << "Yes" << endl;
      exit(0);
    }
    // char s = S[0];
    // S.erase(0, 1);
    // int idx2 = T.find_first_of(s);
    // if (idx2 >= 0)
    // {
    //   T.erase(idx2, 1);
    // }
    // else
    // {
    //   cout << "No" << endl;
    //   exit(0);
    // }
  }
  // cout << "Yes" << endl;
  cout << "No" << endl;

  return 0;
}