// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/description/

/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
  function dfs(x, y) {
    board[x][y] = '#';
    visited[x][y] = true;

    for (let i = 0; i < d.length; i++) {
      const newx = x + d[i][0], newy = y + d[i][1];
      if (inArea(newx, newy)) {
        if (!visited[newx][newy] && board[newx][newy] === 'O') {
          dfs(newx, newy);
        }
      }
    }
  }

  function inArea(x, y) {
    return x >= 0 && x < m && y >=0 && y < n;
  }

  const d = [ [0, 1], [1, 0], [-1 ,0], [0, -1]];
  const m = board.length;
  if (!m) return;
  n = board[0].length;
  const visited = [];
  for (let i = 0; i < m; i++) {
    visited.push(new Array(n).fill(false));
  }

  for (let i = 0; i < m; i++) {
    if (board[i][0] === 'O' && !visited[i][0]) dfs(i, 0);
    if (board[i][n-1] === 'O' && !visited[i][n-1]) dfs(i, n-1);
  }

  for (let j = 0; j < n; j++) {
    if (board[0][j] === 'O' && !visited[0][j]) dfs(0, j);
    if (board[m-1][j] === 'O' && !visited[m-1][j]) dfs(m-1, j);
  }

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (board[i][j] === 'O') {
        board[i][j] = 'X';
      } else if (board[i][j] === '#') {
        board[i][j] = 'O';
      }
    }
  }
};

const board = [
  ['X', 'X', 'X', 'X'],
  ['X', 'O', 'X', 'X'],
  ['O', 'X', 'O', 'O'],
  ['X', 'O', 'X', 'X']
];
solve(board);
console.info(board);
