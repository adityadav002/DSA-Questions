#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
  void tohCal(int N, int source, int help, int dest)
  {
    if (N == 1)
    {
      cout << "Move disk 1 from rod " << source << " to rod " << dest << endl;
      return;
    }

    tohCal(N - 1, source, dest, help);
    cout << "Move disk " << N << " from rod " << source << " to rod " << dest << endl;
    tohCal(N - 1, help, source, dest);
  }

  long long toh(int N, int from, int to, int aux)
  {
    tohCal(N, from, aux, to);
    return pow(2, N) - 1;
  }
};

int main()
{
  Solution sol;
  int N = 3;
  long long totalMoves = sol.toh(N, 1, 3, 2);
  cout << "Total moves: " << totalMoves << endl;
  return 0;
}
