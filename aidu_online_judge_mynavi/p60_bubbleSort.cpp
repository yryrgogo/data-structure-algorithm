#include <iostream>
using namespace std;
static const int MAX = 100;

void trace(int A[], int N){
  for (int i = 0; i < N; i++){
    if (i > 0) cout << ' ';
    cout << A[i];
  }
  cout << '\n';
}

int bubbleSort(int A[], int N){

  bool flag = 1;
  int i = 0;
  int cnt = 0;

  while (flag){
    flag = 0;
    for (int j = N-1; j >= i+1; j--){
      if (A[j-1] > A[j]){
        swap(A[j], A[j-1]);
        flag = 1;
        cnt++;
      }
    }
    i++;
  }

  return cnt;
}

int main (){

  int A[MAX], N, cnt;

  cin >> N;

  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  // main関数で宣言されているAなので、別関数内での変更も反映される（グローバル変数扱い？）
  cnt = bubbleSort(A, N);

  trace(A, N);
  cout << cnt;

  return 0;
}