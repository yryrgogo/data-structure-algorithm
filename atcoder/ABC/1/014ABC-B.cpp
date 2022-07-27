#include <iostream>
#include <string>
using namespace std;

int main()
{

  string S;
  cin >> S;

  int cnt = 0;

  if (S[0] == 'A')
  {
    cnt++;
  }
  else
  {
    cout << "WA" << endl;
    exit(0);
  }

  int first_idx = 2, second_idx = S.size() - 2;
  int idx;
  for (int p = 0; p < S.size(); p++)
  {
    idx = S.find('C');
    if (idx <= first_idx & second_idx <= idx)
    {
      cnt++;
    }
    else if (idx <= second_idx & first_idx <= idx)
    {
      cnt++;
    } else {
      break;
    }
    S.erase(idx, 1);
  }

  if (cnt > 2 || cnt == 1)
  {
    cout << "WA" << endl;
    exit(0);
  }

  S.erase(0, 1);

  for (int i = 0; i < S.size(); i++) {
    if (islower(S[i])){
      cnt++;
    } else {
      cout << "WA"<< endl;
      exit(0);
    }
  }

  cout << "AC" << endl;

  return 0;
}