#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 1000000;

long long cnt;
vector<int> G;

void insertionSort(int A[], int N, int g) {
  for ( int i = g; i < N; i++) {
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j+g]= A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int N){

  int h = 1;
  while (h < N){
    G.push_back(h);
    h = (h*3)+1;
  }

  for (int i = G.size() - 1; i >= 0; i--)
    insertionSort(A, N, G[i]);
}

int main() {

  int A[MAX], N;

  cin >> N;
  for ( int i = 0 ; i < N; i++) scanf("%d", &A[i]);

  shellSort(A, N);

  for (int i = 0; i < N; i++)
    cout << A[i] << endl;
  cout << cnt;

  return 0;
}