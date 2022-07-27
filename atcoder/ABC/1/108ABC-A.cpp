/* ABC108 */
/* A */
#include <iostream>
using namespace std;

int main(void){

  int K;

  cin >> K;

  if (K%2 == 1){
    cout << (K/2) * ((K/2) + 1);
  } else {
    cout << (K/2) * (K/2);
  }

}