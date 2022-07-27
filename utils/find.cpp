#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vec_find(vector<int> vec, int num)
{
  auto found_itr = find(vec.begin(), vec.end(), num);
  bool found = found_itr != vec.end();

  if (found)
  {
    int index = distance(vec.begin(), found_itr);
    return index;
  }

  return -1;
}

int main()
{
  vector<int> vec = {1, 2, 3};

  cout << vec_find(vec, 1) << endl;
  cout << vec_find(vec, 10) << endl;
}