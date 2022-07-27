/* ABC105 */
/* A */
#include <iostream>
using namespace std;

int main(void){

  int N, K;
  cin >> N >> K;

  if (K > 0 && N % K > 0){
    cout << 1;
  } else {
    cout << 0;
  }
}