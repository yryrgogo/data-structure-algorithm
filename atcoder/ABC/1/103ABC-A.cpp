/* ABC103 */
/* A */
#include <iostream>
using namespace std;

void insertionSort(int A[], int N){
  for ( int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
}

int main(void){

  int A[3];

  for ( int i = 0; i < 3; i++){
    cin >> A[i];
  }

  insertionSort(A, 3);

  int cost = 0;
  for ( int i = 1; i < 3; i++) {
    cost += abs(A[i-1] - A[i]);
  }

  cout << cost;

  return 0;
}