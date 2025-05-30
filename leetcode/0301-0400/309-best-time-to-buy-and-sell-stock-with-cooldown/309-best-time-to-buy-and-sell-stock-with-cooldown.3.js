/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let sold = 0, hold = Number.MIN_SAFE_INTEGER, rest = 0;
  for (let price of prices) {
    let preSold = sold;
    sold = hold + price;
    hold = Math.max(hold, rest - price);
    rest = Math.max(rest, preSold);
  }
  return Math.max(sold, rest);
};

console.info(maxProfit([1, 2, 3, 0, 2]));
console.info(maxProfit([]));
