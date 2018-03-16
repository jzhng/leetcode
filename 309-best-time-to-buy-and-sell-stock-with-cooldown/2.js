/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let sell = 0, preSell = 0, buy = Number.MIN_SAFE_INTEGER, preBuy;
  for (let price of prices) {
    preBuy = buy;
    buy = Math.max(preSell - price, preBuy);
    preSell = sell;
    sell = Math.max(preBuy + price, preSell);
  }
  return sell;
};

console.info(maxProfit([1, 2, 3, 0, 2]));
console.info(maxProfit([]));
