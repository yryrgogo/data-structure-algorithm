#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long cnt;
int A[1000000];
int n;
vector<int> G;

// 間隔gを指定した挿入ソート
void insertionSort(int A{}, int n, int g) {
  // ああ, iがgから始まることで、間隔gの数列サイズも増えていくのか。挿入ソートでは未ソートの先頭から前の数列しか参照することしかないから、ソートする数列を捉える時に感覚がそもそも前からではない。その感覚が自分の中にないので勘違いする(どう後ろ間隔gにおける要素をループ毎に増やしていくかなどと)
  for (int i = g; i < n; i++){
    int v = A[i];
    // ああ、未ソートの最後尾は-gした位置にすれば良いのか
    // 間隔gの数のみ抽出した部分列を別途作る必要などなかった
    int j = i - g;
    // そうだよなあ。挿入ソートの特性がソート済配列の最後尾を参照していくことと理解してれば、間隔gが1でなくても同じ形で実装できると気付けるよなあ。頭固いなあ
    while ( j >= 0 && A[j] > v) {
      // ソート済みの部分列において位置を後ろにずらすときも、j+1をj+gにするだけで良い。そりゃそうだな
      A[j + g] = A[j];
      // j--もgの間隔で前の位置に戻るので、j-=g
      j -= g;
      cnt++;
    }
    // 未ソートの部分列の先頭の数字がおさまる位置も最後にソート済みの数字があった場所（1つ後ろに移動済み）
    A[j + g] = v;
  }
}

void shellSort(int A[], int n){
  // 数列G = {1, 4, 13, 40, 121, 364, 1093, ...}を生成
  for (int h = 1; ; ) {
    if (h > n) break;
    G.push_back(h);
    h = 3*h + 1;
  }

  // 逆順にGの要素を入れていく/
  for ( i = G.size()-1; i >= 0; i--) {
    insertionSort(A, n, G[i])
  }
}

int main() {
  cin >> n;

  for ( int i = 0; i < n; i++) scanf("%d", &A[i]);
  cnt = 0;

  shellSort(A, n);

  cout << G.size() << endl;
  for ( int i = G.size() - 1; i >= 0; i--){
    printf("%d", G[i]);
    if ( i ) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  for ( int i = 0; i < n; i++) printf("%d\n", A[i]);

  return 0;
}