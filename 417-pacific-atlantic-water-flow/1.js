// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var pacificAtlantic = function(matrix) {
  function dsf(x, y, visited) {
    visited[x][y] = true;
    for (let i = 0; i < 4; i++) {
      const newx = x + d[i][0], newy = y + d[i][1];
      if (inArea(newx, newy) && !visited[newx][newy]
          && matrix[x][y] <= matrix[newx][newy]) {
        dsf(newx, newy, visited);
      }
    }
  }

  function inArea(x, y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  const res = [], m = matrix.length;
  if (!m) return res;
  const n = matrix[0].length;
  const d = [[0, 1], [1, 0], [-1, 0], [0, -1]];
  const pacific = [], atlantic = [];
  for (let i = 0; i < m ; i++) {
    pacific.push(new Array(n).fill(false));
    atlantic.push(new Array(n).fill(false));
  }

  for (let i = 0; i < m ; i++) {
    dsf(i, 0, pacific);
    dsf(i, n - 1, atlantic);
  }

  for (let j = 0; j < n; j++) {
    dsf(0, j, pacific);
    dsf(m - 1, j, atlantic);
  }

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (pacific[i][j] && atlantic[i][j]) {
        res.push([i, j]);
      }
    }
  }
  return res;
};

const matrix1 = [
  [1, 2, 2, 3, 5],
  [3, 2, 3, 4, 4],
  [2, 4, 5, 3, 1],
  [6, 7, 1, 4, 5],
  [5, 1, 1, 2, 4]
];

const matrix2 = [
  [10, 10, 10],
  [10, 1, 10],
  [10, 10, 10]
];

const matrix3 = [
  [1,2,3],
  [8,9,4],
  [7,6,5]
];

console.info(pacificAtlantic(matrix1));
// console.info(pacificAtlantic(matrix2));
// console.info(pacificAtlantic(matrix3));
