// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  const n = prices.length;
  if (!n) return 0;
  
  const profits = new Array(n).fill(0);
  for (let i = 1; i < n; i++) {
    for (let j = i - 1; j >= 0; j--) {
      let currProfit = prices[i] - prices[j];
      currProfit = (currProfit > 0 ? currProfit : 0);
      profits[i] = Math.max(profits[i], profits[j], (profits[j - 2] || 0) + currProfit);
    }
  }
  return profits[n-1];
};

console.info(maxProfit([1, 2, 3, 0, 2]));
console.info(maxProfit([]));
