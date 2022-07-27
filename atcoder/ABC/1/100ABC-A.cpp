/* ABC120 */
/* A */
#include <iostream>
#include <string>
using namespace std;

int main(void){

    int A, B, C;
    cin >> A >> B >> C;

    int S;
    S = B / A;

    if (S < C) cout << S << endl;
    else if (S >= C) cout << C << endl;
}

