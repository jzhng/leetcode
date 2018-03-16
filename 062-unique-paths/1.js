// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/description/

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  const paths = new Array(m+1).fill(1);

  for (let j = 2; j <= n; j++) {
    for (let i = 2; i <= m; i++) {
      paths[i] += paths[i-1];
    }
  }

  return paths[m];
};

console.info(uniquePaths(1,1));
console.info(uniquePaths(2,3));
