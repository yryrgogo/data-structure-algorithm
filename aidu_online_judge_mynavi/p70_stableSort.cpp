#include <iostream>
using namespace std;
static const int MAX = 36;

struct Card { char suit, value; };

void trace(Card C[], int N){
  for (int i = 0; i < N; i++){
    if (i > 0) cout << ' ';
    cout << C[i].suit << C[i].value;
  }
  cout << endl;
}

bool checkStable(Card in[], Card out[], int N){
  for (int i = 1; i < N; i++){
    if(out[i].value == out[i-1].value && out[i].suit == out[i].suit){
      for (int j = 1; j < N; j++){
        if (out[i-1].value != in[j-1].value){
          return false;
        } else {
          for (int k = j+1; k < N; k++){
            if ( out[i].value != in[k].value && in[i].suit != in[k].suit){
              return false;
            }
          }
        }
      }
    }
  }

  return true;
}

void bubbleSort(Card C[], int N){
  bool flag = 1;
  int i = 0;
  while (flag){
    flag = 0;
    for (int j = N - 1; j >= i+1; j--){
      if (C[j].value < C[j-1].value){
        swap(C[j], C[j-1]);
        flag = 1;
      }
    }
    i++;
  }
}

void selectionSort(Card C[], int N){
  int minj;
  for (int i = 0; i < N; i++){
    minj = i;
    for (int j = i+1; j < N; j++){
      if (C[minj].value > C[j].value){
        minj = j;
      }
    }
    if (minj != i) swap(C[minj], C[i]);
  }
}

int main(){
  Card C1[MAX], C2[MAX];
  int N;
  bool isStable;

  cin >> N;

  for (int i = 0; i < N; i++){
    cin >> C1[i].suit >> C1[i].value;
  }
  for (int i = 0; i < N; i++){
    C2[i] = C1[i];
  }

  bubbleSort(C1, N);
  trace(C1, N);
  isStable = checkStable(C1, C2, N);
  cout << isStable << endl;
  selectionSort(C2, N);
  trace(C2, N);
  isStable = checkStable(C1, C2, N);
  cout << isStable << endl;

  return 0;
}