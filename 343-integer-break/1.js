// 343. Integer Break
// https://leetcode.com/problems/integer-break/description/

/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
  if (n === 1) return 1;

  let res = -1;
  for (let i = 1; i < n; i++) {
    res = Math.max(res, i * (n-i), i * integerBreak(n-i));
  }
  return res;
};

console.info(integerBreak(10));
