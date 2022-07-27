#include <stdio.h>
#define LEN 100005

/* プロセスを表す構造体 */
typedef struct pp {
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

// enqueueではtailに新しいqueueを追加してtail+1する
void enqueue(P x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

// dequueではhead-1してからhead+1のqueueを返す
P dequeue() {
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

/* 最小値を返すfunction */
int min(int a, int b) { return a < b ? a : b; }

int main() {
  int elaps = 0, c;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);

  for (i = 1; i <= n; i++ ) {
    scanf("%s", &Q[i].name);
    scanf("%d", &Q[i].t);
  }
  // headは先頭のキューの位置
  head = 1;
  // tailは次のキューが入る位置
  tail = n + 1;

  while ( head != tail ) {
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    elaps += c;
    if ( u.t > 0 )
      enqueue(u);
    else {
      printf("%s %d\n", u.name, elaps);
    }
  }

  return 0;
}