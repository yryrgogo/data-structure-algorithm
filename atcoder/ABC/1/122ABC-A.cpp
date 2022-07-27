/* ABC122 */
/* A. Double Helix */
#include <iostream>
#include <string>
using namespace std;

int main(void){

    string b1, b2;
    cin >> b1;

    if (b1=="A")
        b2 = "T";
    else if (b1=="T")
        b2 = "A";
    else if (b1=="C")
        b2 = "G";
    else if (b1=="G")
        b2 = "C";
    
    cout << b2 << endl;
}