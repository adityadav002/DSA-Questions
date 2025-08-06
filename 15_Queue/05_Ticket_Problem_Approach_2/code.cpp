#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }
        return time;
    }
};

int main() {
    Solution solution;
    vector<int> tickets = {2, 3, 2};  
    int k = 2;                        
    int result = solution.timeRequiredToBuy(tickets, k);
    cout << "Time required to buy tickets: " << result << endl;
    return 0;
}
