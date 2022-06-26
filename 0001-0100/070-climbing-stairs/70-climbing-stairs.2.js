/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  function calcWays(n) {
    if (n === 0 || n === 1) {
      return 1;
    }

    if (ways[n] === -1) {
      ways[n] = calcWays(n-1) + calcWays(n-2);
    }

    return ways[n];
  }

  const ways = new Array(n+1).fill(-1);
  return calcWays(n);
};

console.info(climbStairs(5));
