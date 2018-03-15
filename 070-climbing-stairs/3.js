/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  const ways = [1, 1]

  for (let i = 2; i <= n; i++) {
    ways[i] = ways[i-1] + ways[i-2];
  }
  return ways[n];
};

console.info(climbStairs(5));
