#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        if (n == 1) return 0;
        int l = 0, r = 1;
        while (l < n) {
            while (r < n && prices[r-1] < prices[r]) {
                ++r;
            }
            profit += (prices[r-1] - prices[l]);
            l = r;
            ++r;
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    vector<int> prices2 = {7,6,4,3,1};
    cout << s.maxProfit(prices2) << endl;
    vector<int> prices3 = {1,2,3,4,5};
    cout << s.maxProfit(prices3) << endl;
    vector<int> prices4 = {1,2,3,4,5,6};
    cout << s.maxProfit(prices4) << endl;
    return 0;
}
