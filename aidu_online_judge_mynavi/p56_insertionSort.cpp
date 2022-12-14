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

void insertionSort(int A[], int N){
  // ここでiはソート候補の数のインデックスになっている
  for (int i = 1; i < N; i++){
    int j, x;
    // ソート候補の数を取り出しておき、配列が更新されても消えないようにする
    x = A[i];
    // ここでソート済みの数の最後尾のインデックスを用意する
    j = i - 1;
    // ソート済みの配列の中で、ソート候補の数がどこに入るかを計算する。
    // 最後尾の数から順に、ソート済みの数よりソート候補の数が小さければ、その数は今の位置より1つ後ろにずらす。後ろにずらした時、その数が元の位置に残るが、そこでソートが完了した場合はソート候補の数がその位置に入る。ソートが続く場合は、その前のインデックスの数がその位置にずれてくる。
    while (0 <= j & A[j] > x) {
      // ソート済みの数よりソート候補の数の方が小さいので、1つ後ろにずらす
      A[j+1] = A[j];
      // ソート済みの数で、1つ前の数とソート候補の数を比較するために-1する
      j--;
    }
    // ソート候補の数がどこに入るかは最後に決まる。ソートが発生しない場合は元いた位置におさまる。
    A[j+1] = x;
  }

  trace(A, N);
}

int main(){
  int A[MAX], N;

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  insertionSort(A, N);

  return 0;
}