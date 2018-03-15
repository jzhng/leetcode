// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/description/

/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
  function putNumber(x, y) {
    x += Math.floor(y / n);
    y %= n;
    if (x > n - 1) return true;
    if (board[x][y] !== '.') {
      return putNumber(x, y + 1);
    }

    for (let i = 0; i < nums.length; i++) {
      const c = nums[i];
      const sid = Math.floor(x / 3) * 3 + Math.floor(y / 3);
      if (!row[x][c] && !col[y][c] && !square[sid][c]) {
        board[x][y] = c;
        row[x][c] = col[y][c] = square[sid][c] = true;
        if (putNumber(x, y + 1)) {
          return true;
        } else {
          row[x][c] = col[y][c] = square[sid][c] = false;
          board[x][y] = '.';
        }
      }
    }
    return false;
  }

  const nums = '123456789';
  const n = board.length;
  if (!n) return;

  const row = [], col = [], square = [];
  for (let i = 0; i < n; i++) {
    row.push(new Array(n + 1).fill(false));
    col.push(new Array(n + 1).fill(false));
    square.push(new Array(n + 1).fill(false));
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const c = board[i][j];
      if (c !== '.') {
        row[i][c] = true;
        col[j][c] = true;
        square[Math.floor(i / 3) * 3 + Math.floor(j / 3)][c] = true;
      }
    }
  }
  putNumber(0, 0);
};

const board = [
  ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
  ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
  ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
  ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
  ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
  ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
  ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
  ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
  ['.', '.', '.', '.', '8', '.', '.', '7', '9']
]
solveSudoku(board);
console.info(board);
