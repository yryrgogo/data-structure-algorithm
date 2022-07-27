#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int> &a, int i, int N)
{
  int child1 = i * 2 + 1; // left child
  if (child1 >= N)
    return; // end when there are no children

  // compare children
  if (child1 + 1 < N && a[child1 + 1] > a[child1])
    ++child1;
}