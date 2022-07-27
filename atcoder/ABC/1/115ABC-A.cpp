/* ABC115 */
/* A */
#include <iostream>
using namespace std;

int main(void)
{

  int D, diff;

  cin >> D;
  diff = 25 - D;

  string today;
  today = "Christmas";
  for (int i = 0; i < diff; i++)
  {
    today += " Eve";
  }
  cout << today;
}