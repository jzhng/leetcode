#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int np = prices.size();
        int profit = 0;
        int mp = prices[0];
        for (int i = 1; i < np; ++i) {
            mp = min(mp, prices[i]);
            profit = max(profit, prices[i] - mp);
        }
        return profit;
    }
};