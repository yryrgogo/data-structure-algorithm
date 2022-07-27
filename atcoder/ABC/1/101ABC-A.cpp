/* ABC101 */
/* A */
#include <iostream>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){

  int N = 4;
  int num = 0;
  char s[N];

  for ( int i = 0; i < N; i++) {
    cin >> s[i];
  }

  for ( int i = 0; i < N; i++ ) {
    if (s[i] == '+') {
      num += 1;
    } else if (s[i] == '-') {
      num -= 1;
    }
  }

  cout << num;
}
