#include <iostream>
using namespace std;

int main()
{
  // break;
  for (int i = 1; i <= 10; i++)
  {
    if (i == 5)
    {
      break;
    }
    cout << i << " ";
  }

  // continue;
  cout << endl;
  for (int i = 1; i <= 10; i++)
  {
    if (i == 5)
    {
      continue;
    }
    cout << i << " ";
  }
  return 0;
}