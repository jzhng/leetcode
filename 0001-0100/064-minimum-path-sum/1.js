// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/description/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
  const m = grid.length, n = grid[0].length;
  const min = [];
  for (let i = 0; i < m; i++) {
    min.push(new Array(n).fill(null));
  }
  min[0][0] = grid[0][0];

  for (let i = 1; i < m; i++) {
    min[i][0] = min[i-1][0] + grid[i][0];
  }

  for (let j = 1; j < n; j++) {
    min[0][j] = min[0][j-1] + grid[0][j];
  }

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      min[i][j] = Math.min(min[i-1][j], min[i][j-1]) + grid[i][j];
    }
  }

  return min[m-1][n-1];
};

const grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
];

console.info(minPathSum(grid));
