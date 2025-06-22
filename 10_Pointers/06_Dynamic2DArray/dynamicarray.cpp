#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  // Create 2D Array.
  int **ptr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    ptr[i] = new int[m];
  }

  // Input Value.
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> ptr[i][j];
    }
  }
  // Print Value.
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ptr[i][j] << " ";
    }
    cout << endl;
  }

  // Release Memory.
  for (int i = 0; i < n; i++)
  {
    delete[] ptr[i];
  }
  delete[] ptr;

  return 0;
}