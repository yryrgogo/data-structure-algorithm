/* ABC104 */
/* A */
#include <iostream>
using namespace std;

int main(void){

  int R;

  cin >> R;

  if ( R < 1200) {
    cout << "ABC";
  } else if ( R < 2800) {
    cout << "ARC";
  } else {
    cout << "AGC";
  }
}