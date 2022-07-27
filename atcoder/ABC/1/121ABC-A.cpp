/* ABC122 */
/* A */
#include <iostream>
#include <string>
using namespace std;

int main(void){

    int H, W, h, w;
    cin >> H >> W;
    cin >> h >> w;

    int rem;
    rem = (H-h) * (W-w);
    cout << rem << endl;
}