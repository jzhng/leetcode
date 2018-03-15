/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
  const max = [0, 1];
  for (let i = 2; i <= n; i++) {
    for (let j = 1; j < i; j++) {
      max[i] = Math.max(max[i] || -1, j * (i - j), j * max[i - j]);
    }
  }
  return max[n];
};

console.info(integerBreak(10));
