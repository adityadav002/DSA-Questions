#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 1, end = *max_element(piles.begin(), piles.end()), mid, ans;
    
    while (start <= end)
    {
        mid = start + (end - start) / 2;   // Current eating speed (bananas per hour)
        
        int total_time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            total_time += (piles[i] + mid - 1) / mid; // Equivalent to ceil(piles[i] / mid)
        }
        
        if (total_time <= h)
        {
            ans = mid;  // We can finish in time with this speed, so store it as a candidate answer
            end = mid - 1;  // Try for a smaller eating speed
        }
        else
        {
            start = mid + 1;  // We need to eat faster to finish in time, so try a larger speed
        }
    }
    
    return ans;
}

int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;

    int result = minEatingSpeed(piles, h);
    cout << result << endl; 
    return 0;
}
