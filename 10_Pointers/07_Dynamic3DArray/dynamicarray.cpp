#include <iostream>
using namespace std;

int main()
{
  int l, b, h;
  cin >> l >> b >> h;

  // Create 3D Array.
  int ***ptr = new int **[l];
  for (int i = 0; i < l; i++)
  {
    ptr[i] = new int *[b];
    for (int j = 0; j < b; j++)
    {
      ptr[i][j] = new int[h];
    }
  }

  // Input Value.
  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < b; j++)
    {
      for (int k = 0; k < h; k++)
      {
        cin >> ptr[i][j][k];
      }
    }
  }

  // Print Value.
  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < b; j++)
    {
      for (int k = 0; k < h; k++)
      {
        cout << ptr[i][j][k] << " ";
      }
    }
    cout << endl;
  }

  // Release Memory.
  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < b; j++)
    {
      delete[] ptr[i][j];
    }
    delete[] ptr[i];
  }
  delete[] ptr;
  return 0;
}