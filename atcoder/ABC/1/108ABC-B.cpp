#include <iostream>
#include <string>
using namespace std;

int main()
{

  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;

  int diffX = x2 - x1;
  int diffY = y2 - y1;

  x3 = x2 - diffY;
  y3 = y2 + diffX;
  x4 = x1 - diffY;
  y4 = y1 + diffX;

  printf("%d %d %d %d\n", x3, y3, x4, y4);
}