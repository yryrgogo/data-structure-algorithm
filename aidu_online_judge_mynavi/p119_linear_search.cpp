#include<iostream>
using namespace std;

bool linearSearch(int S[], int N, int x) {

  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == x) {
      return true;
    }
  }

  return false;
}

int main() {

  int n, q;

  cin >> n ;
  int S[n];

  for (int i = 0; i < n; i++){
    cin >> S[i];
  }

  cin >> q;
  int T[q];

  int cnt = 0;
  for (int i = 0; i < q; i++) {
    cin >> T[i];

    bool isIn = linearSearch(S, n, T[i]);

    if (isIn){
      cnt++;
    }
  }

  cout << cnt;
}