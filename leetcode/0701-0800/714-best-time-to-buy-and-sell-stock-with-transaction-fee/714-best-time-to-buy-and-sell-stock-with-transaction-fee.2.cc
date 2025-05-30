class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int minPrice = prices[0] + fee;
        for (int i = 1; i < prices.size(); ++i) {
            if (minPrice > prices[i] + fee) {
                minPrice = prices[i] + fee;
            } else if (prices[i] > minPrice) {
                profit += prices[i] - minPrice;
                minPrice = prices[i];
            }
        }

        return profit;
    }
};
