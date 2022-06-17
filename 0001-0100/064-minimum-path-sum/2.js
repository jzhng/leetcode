/**
 * @param {number[][]} grid
 * @return {number}
 */

var minPathSum = function(grid) {
  const m = grid.length, n = grid[0].length;
  const min = [ grid[0][0] ];

  for (let i = 1; i < m; i++) {
    min[i] = min[i-1] + grid[i][0];
  }

  for (let j = 1; j < n; j++) {
    min[0] += grid[0][j];
    for (let i = 1; i < m; i++) {
      min[i] = Math.min(min[i-1], min[i]) + grid[i][j];
    }
  }

  return min[m-1];
};

const grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
];

console.info(minPathSum(grid));
