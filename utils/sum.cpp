#include<iostream>
using namespace std;

template <typename T>
T sum(T first) {
  return first;
}

template <typename T, typename ... Args>
T sum(T first, Args ... others) {
  return first + sum(others...);
}

int main(){
  cout << sum(1, 2, 3, 4, 5);

  return 0;
}