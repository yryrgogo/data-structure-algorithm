/* ABC120 */
/* A */
#include <iostream>
using namespace std;

int main(void){

    int A, B, C;
    cin >> A >> B >> C;

    // sortライブラリ使えば良いのだが

    if (A >= B && A >= C){
      cout << 10 * A + B + C;
    } else if (B >= A && B >= C){
      cout << 10 * B + A + C;
    } else if (C >= A && C >= B){
      cout << 10 * C + B + A;
    }
}