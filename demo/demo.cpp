#include <iostream>
#include <tkutils/tkutils.hpp>

using namespace std;
using namespace tkht;

bool descending(int a, int b) { return a > b; }

int main() {
  TKArray<int> array, ret;

  for (int i = 0; i < 10; i++) {
    array.push_diff(i);
  }

  ret = array - array[0];

  for (int v : ret)
    cout << v << ", ";
  cout << endl;

  array.sort(descending);

  for (int v : array)
    cout << v << ", ";
  cout << endl;

  return 1;
}