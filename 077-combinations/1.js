// 77. Combinations
// https://leetcode.com/problems/combinations/description/

/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
  function generateCombinations(pos, c) {
    if (c.length === k) {
      res.push(c.slice());
    } else {
      // i <= n optimized
      let m = n - (k - c.length) + 1;
      for (let i = pos; i <= m; i++) {
        c.push(i);
        generateCombinations(i+1, c);
        c.pop(i);
      }
    }
  }
    
  const res = [];
  if (n <= 0 || k <= 0 || k > n) return res;
  generateCombinations(1, []);
  return res;
};

console.info(combine(4, 2))
