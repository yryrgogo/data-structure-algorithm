#include <iostream>
#include <stdio.h>
using namespace std;
static const int MAX = 200;

int top = 0;
int S[MAX];

void initialize() {
  top = 0;
}

void push(int x) {
  top++;
  S[top] = x;
}

int pop() {
  top--;
  return S[top+1];
}

bool isEmpty() {
  return top == 0;
}

bool isFull() {
  return top == MAX-1;
}

int main(){

  char s[MAX];
  int a, b;

  // EOF は Ctrl + d　で起こるよ。無駄にハマった
  while ( scanf("%s", &s) != EOF ) {
    if ( s[0] == '+' ) {
      a = pop();
      b = pop();
      push( a + b );
    } else if ( s[0] == '-' ) {
      a = pop();
      b = pop();
      push( a - b );
    } else if ( s[0] == '*' ) {
      a = pop();
      b = pop();
      push( a * b );
    } else {
      push(atoi(s));
    }
  }

  cout << pop() << endl;

  return 0;
}