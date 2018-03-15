// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/

/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  function calcWays(n) {
    if (n === 0 || n === 1) {
      return 1;
    }
    return calcWays(n-1) + calcWays(n-2);
  }

  return calcWays(n);
};

console.info(climbStairs(5));
