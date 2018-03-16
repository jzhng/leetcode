// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/description/

/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
  const m = obstacleGrid.length, n = obstacleGrid[0].length;
  const paths = new Array(m).fill(0);

  paths[0] = 1;
  for (let j = 0; j < n; j++) {
    for (let i = 0; i < m; i++) {
      if (obstacleGrid[i][j]) {
        paths[i] = 0;
      } else if (i > 0) {
        paths[i] += paths[i-1];
      }
    }
  }

  return paths[m-1];
};

const grid1 = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
];

const grid2 = [[0],[1]];
const grid3 = [[1]];

console.info(uniquePathsWithObstacles(grid1));
console.info(uniquePathsWithObstacles(grid2));
console.info(uniquePathsWithObstacles(grid3));

