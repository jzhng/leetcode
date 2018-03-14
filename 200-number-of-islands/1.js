// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
  function dfs(x, y) {
    visited[x][y] = true;
    for (let i = 0; i < d.length; i++) {
      let newx = x + d[i][0], newy = y + d[i][1];
      if (inArea(newx, newy) && !visited[newx][newy]
          && grid[x][y] === '1') {
        dfs(newx, newy);
      }
    }
  }

  function inArea(x, y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  const m = grid.length;
  if (!m) return 0;
  const n = grid[0].length;
  const d = [[1, 0], [0, 1], [-1, 0], [0, -1]];
  const visited = [];
  for (let i = 0; i < m; i++) {
    visited.push(new Array(n).fill(false));
  }

  let res = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (!visited[i][j] && grid[i][j] === '1') {
        res++;
        dfs(i, j);
      }
    }
  }
  return res;
};

const grid = [
  ['1', '1', '0', '0', '0'],
  ['1', '1', '0', '0', '0'],
  ['0', '0', '1', '0', '0'],
  ['0', '0', '0', '1', '1']
]
console.info(numIslands(grid));
