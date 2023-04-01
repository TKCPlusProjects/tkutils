#include <iostream>
#include <tkutils/tkutils.hpp>

using namespace std;
using namespace tkht;

int main() 
{
  TKArray<int> array, ret;

  for (int i = 0; i < 10; i++)
  {
    array ^= i;
  }

  ret = array - array[0];

  for (int v : array) cout << v << ", ";
  cout << endl;
  for (int v : ret) cout << v << ", ";
  cout << endl;

  return 1;
}