#include <iostream>
#include <tkutils/tkutils.hpp>

using namespace std;
using namespace tkht;

int main() 
{
  TKList<int> list;

  for (int i = 0; i < 10; i++)
  {
    list <<= i;
  }

  for (int v : list)
  {
    cout << v << ", " << endl;
  }

  return 1;
}