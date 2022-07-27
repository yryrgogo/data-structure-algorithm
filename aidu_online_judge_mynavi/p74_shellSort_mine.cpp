#include <iostream>
#include <string>
using namespace std;
static const int MAX = 36;

void trace(int A[], int N) {
  for (int i = 0; i < N; i++){
    cout << A[i];
    cout << ' ';
  }
  cout << endl;
}

int insertionSort(int A[], int N, int cnt){

  // 未ソートの部分列の先頭を指すループ変数をiで定義
  for (int i = 1; i < N; i++){

    int v = A[i];
    // ソート済みの部分列を最後尾から前にかけて示すループ変数をjで定義
    int j = i - 1;
    // A[i]は最初のA[j+1]で書き換わるので、ループの条件式に入れてはいけない
    while (j >= 0 & A[j] > v){
      // A[i]の方がA[j]より小さい状態なので、A[j]を1つ後ろにずらす
      A[j+1] = A[j];
      cnt++;
      j--;
    }
    // A[i]より小さいA[j]ではないポイントにjがきたらwhileを抜ける. そのA[j]はA[i]より小さいので、そのまま
    // よって、位置をずらした最後のポイントはj+1になり、そこがA[i]の入る場所になる
    A[j+1] = v;
  }

  return cnt;
}

int shellSort(int A[], int N, int g, int cnt){
  int sn = (N / g) + 1;
  // shellSortを行う開始位置を決めるループ変数をiで定義
  for (int i = 0; i < N; i++){
    // shellSortを行う数列を作成
    int S[sn];
    int scnt = 0;
    for (int j = 0; j < sn; j++){
      if (i + g*j < N){
        S[j] = A[i + g*j];
        scnt++;
      }
    }
    if (scnt == 1){
      return cnt;
    }
    cnt = insertionSort(S, scnt, cnt);
    for (int j = 0; j < sn; j++){
      if (i + g*j < N){
        A[i + g*j] = S[j];
      }
    }
  }
  return cnt;
}

int main() {

  int A[MAX], N;
  int cnt = 0;

  cin >> N;

  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  cnt = shellSort(A, N, 4, cnt);
  trace(A, N);
  cnt = shellSort(A, N, 3, cnt);
  trace(A, N);
  cnt = shellSort(A, N, 1, cnt);
  trace(A, N);

  cout << cnt << endl;

  return 0;
}