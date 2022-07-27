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

int selectionSort(int A[], int N) {

  int sw = 0;
  // 未ソートの部分列の先頭を示すループ変数をiで定義する
  for (int i = 0; i < N; i++) {
    // 探索した中で最小値を示すインデックスをminjで定義する
    // 最初は未ソートの先頭要素が最小であると仮に定義する
    int minj = i;
    // 未ソートの部分列の中で最小値をもつインデックスを探索するループ変数をjで定義する
    for (int j = i+1; j < N; j++) {
      // 現在の最小値よりも小さい値が、未ソートの部分列を前から順に確認する中で登場したら、最小値を示すminjを更新する
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i){
      swap(A[i], A[minj]);
}

int main(){

  int A[MAX], N, sw;

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  sw = selectionSort(A, N);
  trace(A, N);
  cout << sw << endl;
}