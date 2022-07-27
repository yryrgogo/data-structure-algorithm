/* ABC111 */
/* A */
#include <iostream>
using namespace std;

int main(void)
{

  int n;

  cin >> n;

  for (int i = 0; i < to_string(n).length(); i++)
  {
    if (to_string(n)[i] == '1')
    {
      cout << 9;
    }
    else if (to_string(n)[i] == '9')
    {
      cout << 1;
    }
  }
}