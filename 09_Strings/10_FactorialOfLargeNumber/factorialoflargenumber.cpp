#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> factorial(int n)
{
  vector<int> ans(1,1);
  while(n > 1)
  {
    int carry = 0, res, size = ans.size();
    for(int i = 0; i< size; i++)
    {
      res = ans[i] * n + carry;
      ans[i] = res % 10;
      carry = res / 10;
    }
    while(carry)
    {
      ans.push_back(carry % 10);
      carry /= 10;
    }
    n--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n;
  cout << endl << "Enter a number for Factorial : ";
  cin >> n;

  vector<int> result = factorial(n);
    cout << "Factorial of " << n << " is: ";
    for (int digit : result)
    {
        cout << digit;
    }
    cout << endl;

  return 0; 
}